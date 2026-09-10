/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:40:27 by romeo             #+#    #+#             */
/*   Updated: 2026/09/09 18:22:09 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_list(t_env *env_list)
{
	t_env_node	*tmp;

	while (env_list->head != NULL)
	{
		tmp = env_list->head;
		env_list->head = env_list->head->next;
		free(tmp->key);
		free(tmp->val);
		free(tmp);
	}
}

void	error_command(const char *message)
{
	perror(message);
	_exit(EXIT_FAILURE);
}

void	command_not_found(char *cmd, t_shell *shell)
{
	char	*error_message;

	error_message = "Command not found: ";
	write(STDERR_FILENO, error_message, ft_strlen(error_message));
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, "\n", 1);
	shell->exit_status = 127;
	exit(127);
}

static void	handle_exec_error(char *path, t_env *env_list, t_shell *shell)
{
	write(STDERR_FILENO, "Error: Command execution failed\n", 32);
	free(path);
	free_env_list(env_list);
	shell->exit_status = 126;
	exit(126);
}

void	execute_command(t_exec *node, t_env *env_list, t_shell *shell)
{
	char	*resolved_path;
	char	**envp;

	if (ft_strchr(node->execs[0], '/'))
	{
		if (access(node->execs[0], F_OK) == -1)
			command_not_found(node->execs[0], shell);
		if (access(node->execs[0], X_OK) == -1)
			exit(126);
	}
	resolved_path = get_path(node->execs[0], env_list);
	if (!resolved_path)
		command_not_found(node->execs[0], shell);
	envp = env_to_envp(env_list);
	if (!envp)
		exit(1);
	if (execve(resolved_path, node->execs, envp) == -1)
	{
		free_envp(envp);
		handle_exec_error(resolved_path, env_list, shell);
	}
}
