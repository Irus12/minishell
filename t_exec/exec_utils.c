/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:10:36 by romeo             #+#    #+#             */
/*   Updated: 2026/08/31 18:01:55 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	save_fds2(t_shell *shell)
{
	shell->saved_stdin = dup(STDIN_FILENO);
	shell->saved_stdout = dup(STDOUT_FILENO);
	if (shell->saved_stdin == -1 || shell->saved_stdout == -1)
	{
		perror("Failed to save file descriptors");
		if (shell->saved_stdin != -1)
			close(shell->saved_stdin);
		if (shell->saved_stdout != -1)
			close(shell->saved_stdout);
		exit(EXIT_FAILURE);
	}
}

void	restore_fds2(t_shell *shell)
{
	if (shell->saved_stdin != -1)
	{
		if (dup2(shell->saved_stdin, STDIN_FILENO) == -1)
			perror("Failed to restore stdin");
		close(shell->saved_stdin);
		shell->saved_stdin = -1;
	}
	if (shell->saved_stdout != -1)
	{
		if (dup2(shell->saved_stdout, STDOUT_FILENO) == -1)
			perror("Failed to restore stdout");
		close(shell->saved_stdout);
		shell->saved_stdout = -1;
	}
}

// void	execute_exec_list(t_shell *shell, t_exec *cmd_list, t_env *env)
// {
// 	t_exec	*current;

// 	shell->pid_list = init_pid_list();
// 	current = cmd_list;
// 	while (current != NULL)
// 	{
// 		send_to_exec(shell, current, env);
// 		current = current->next;
// 		restore_fds2(shell);
// 	}
// 	wait_all_pids(shell->pid_list, cmd_list);
// 	free_pid_list(shell->pid_list);
// }

void	execute_exec_list(t_shell *shell, t_exec *cmd_list, t_env *env)
{
	t_exec	*current;

	shell->pid_list = init_pid_list();
	current = cmd_list;
	while (current != NULL)
	{
		send_to_exec(shell, current, env);
		current = current->next;
		restore_fds2(shell);
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	wait_all_pids(shell->pid_list, cmd_list, shell);
	ft_signal(1, shell);
	free_pid_list(shell->pid_list);
}

t_fd_backup	save_fds(void)
{
	t_fd_backup	backup;

	backup.saved_stdin = dup(STDIN_FILENO);
	backup.saved_stdout = dup(STDOUT_FILENO);
	if (backup.saved_stdin == -1 || backup.saved_stdout == -1)
	{
		perror("Failed to save file descriptors");
		if (backup.saved_stdin != -1)
			close(backup.saved_stdin);
		if (backup.saved_stdout != -1)
			close(backup.saved_stdout);
		exit(EXIT_FAILURE);
	}
	return (backup);
}

void	restore_fds(t_fd_backup *backup)
{
	if (backup->saved_stdin != -1)
	{
		if (dup2(backup->saved_stdin, STDIN_FILENO) == -1)
			perror("Failed to restore stdin");
		close(backup->saved_stdin);
	}
	if (backup->saved_stdout != -1)
	{
		if (dup2(backup->saved_stdout, STDOUT_FILENO) == -1)
			perror("Failed to restore stdout");
		close(backup->saved_stdout);
	}
}
