/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lexer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:15:53 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 14:17:35 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	skip_whitespace(char *s, int i)
{
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (i);
}

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	reset_shell(t_shell *shell)
{
	if (shell->lex_head)
	{
		free_lex(shell->lex_head);
		shell->lex_head = NULL;
	}
	if (shell->executor)
	{
		free_exec_list(shell->executor);
		shell->executor = NULL;
	}
	if (shell->rl_copy)
	{
		free(shell->rl_copy);
		shell->rl_copy = NULL;
	}
}

t_token_list	*lexer_clean(t_shell *shell, t_token_list *lex_head)
{
	if (shell->rl_copy)
	{
		free(shell->rl_copy);
		shell->rl_copy = NULL;
	}
	if (lex_head)
		free_lex(lex_head);
	return (NULL);
}
