/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:16:08 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 16:27:00 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	ft_signal(5);
	resolved_path = get_path(node->execs[0], env_list);
	if (!resolved_path)
		command_not_found(node->execs[0], shell);
	if (execve(resolved_path, node->execs, NULL) == -1)
		handle_exec_error(resolved_path, env_list, shell);
}
