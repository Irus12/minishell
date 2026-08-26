/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:11:27 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 16:13:00 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handle_unset(t_shell *shell, char **execs)
{
	if (!execs[1])
	{
		printf("unset: not enough arguments\n");
		shell->exit_status = 127;
	}
	else
		unset(shell, &execs[1]);
}

void	handle_builtin(t_shell *shell, t_exec *exec_node)
{
	char	**execs;

	if (!exec_node || !exec_node->execs || !exec_node->execs[0])
		return ;
	execs = exec_node->execs;
	if (ft_strcmp(execs[0], "cd") == 0)
		ft_cd(shell->environ, execs);
	if (ft_strcmp(execs[0], "echo") == 0)
		ft_echo(execs, shell);
	else if (ft_strcmp(execs[0], "export") == 0)
		handle_export(shell, execs);
	else if (ft_strcmp(execs[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(execs[0], "unset") == 0)
		handle_unset(shell, execs);
	else if (ft_strcmp(execs[0], "env") == 0)
		ft_env(shell->environ->head);
	else if (ft_strcmp(execs[0], "exit") == 0)
		ft_exit(shell, execs);
	else if (ft_strcmp(execs[0], "./minishell") == 0)
		ft_mshell(shell, execs);
}
