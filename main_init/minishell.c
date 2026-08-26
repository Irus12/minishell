/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:04:24 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 14:54:06 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_exit_status = 0;

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	(void)argv;
	if (argc != 1)
		return (1);
	shell = init_shell(envp);
	if (!shell || !shell->environ)
		return (1);
	while (1)
		handle_input(shell);
	rl_clear_history();
	if (shell)
	{
		free_env(shell->environ);
		free_exec_list(shell->executor);
		free_lex(shell->lex_head);
		free(shell);
	}
	return (0);
}
