/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_from_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:06:34 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 15:13:16 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	configure_io(t_exec *node)
{
	if (node->fd_in == 0 && node->pipe_in)
		node->fd_in = node->pipe_in;
	if (node->fd_in != 0)
	{
		if (dup2(node->fd_in, STDIN_FILENO) == -1)
		{
			perror("dup2 fd_in");
			_exit(EXIT_FAILURE);
		}
	}
	if (node->fd_out != 1)
	{
		if (dup2(node->fd_out, STDOUT_FILENO) == -1)
		{
			perror("dup2 fd_out");
			_exit(EXIT_FAILURE);
		}
	}
	if (node->fd_in != 0)
		close(node->fd_in);
	if (node->fd_out != 1)
		close(node->fd_out);
}

void	close_fds(t_exec *current)
{
	if (current->pipe_in)
		close(current->pipe_in);
	if (current->pipe_out)
		close(current->pipe_out);
}

void	fork_builtin(t_shell *shell, t_exec *head, t_env *env_list)
{
	t_exec	*curr;
	pid_t	pid;

	(void)env_list;
	curr = head;
	if (curr->fd_in == -1)
	{
		shell->exit_status = 1;
		return ;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		configure_io(curr);
		handle_builtin(shell, curr);
		_exit(EXIT_SUCCESS);
	}
	else
		close_fds(curr);
	add_pid(shell->pid_list, pid);
}

void	fork_external(t_exec *head, t_env *env_list, t_shell *shell)
{
	t_exec	*current;
	pid_t	pid;

	current = head;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		configure_io(current);
		execute_command(current, env_list, shell);
		perror("execve failed");
		_exit(EXIT_FAILURE);
	}
	else
	{
		close_fds(current);
		shell->exit_status = 127;
	}
	add_pid(shell->pid_list, pid);
}

void	send_to_exec(t_shell *shell, t_exec *cmd, t_env *env)
{
	if (cmd == NULL || (cmd->execs == NULL) || cmd->execs[0] == NULL)
	{
		write(STDERR_FILENO, "Invalid command.\n", 17);
		return ;
	}
	if (cmd->fd_in == -1)
	{
		shell->exit_status = 1;
		return ;
	}
	if (is_builtin(cmd->execs[0]) && cmd->piped == 0)
	{
		configure_io(cmd);
		handle_builtin(shell, cmd);
		close_fds(cmd);
	}
	else if (is_builtin(cmd->execs[0]) && cmd->piped == 1)
		fork_builtin(shell, cmd, env);
	else
		fork_external(cmd, env, shell);
}
