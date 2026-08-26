/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:48:47 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 14:02:07 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Here both parsing and execution meets
void	handle_line(t_shell *shell, char *line)
{
	if (!shell || !line || !*line)
		return ;
	shell->rl_input = ft_strdup(line);
	if (!shell->rl_input)
	{
		perror("Failed to allocate input string");
		return ;
	}
	shell->lex_head = parser(shell->rl_input);
	if (!shell->lex_head)
	{
		shell->exit_status = 2;
		free(shell->rl_input);
		shell->rl_input = NULL;
		return ;
	}
	save_fds2(shell);
	shell->executor = create_exec_list(shell);
	if (shell->executor)
		execute_exec_list(shell, shell->executor, shell->environ);

	free(shell->rl_input);
	shell->rl_input = NULL;
}

void	handle_input(t_shell *shell)
{
	char		*line;
	t_fd_backup	fd_backup;

	fd_backup = save_fds();
	ft_signal(1);
	line = readline("minishell> ");
	if (!line)
	{
		printf("\n");
		ft_exit(shell, NULL);
	}
	if (*line)
		add_history(line);
	handle_line(shell, line);
	reset_shell(shell);
	free(line);
	restore_fds(&fd_backup);
}
