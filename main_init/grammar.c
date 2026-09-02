/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:14:33 by romeo             #+#    #+#             */
/*   Updated: 2026/09/02 14:18:38 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_redirection(t_token type)
{
	return (type == TRUNCATE || type == APPEND
		|| type == REDIRECT_INPUT || type == HEREDOC);
}

static int	check_token(t_token_list *token)
{
	if (token->type == PIPE)
	{
		if (!token->prev || !token->next)
		{
			write(2, "syntax error near unexpected token `|'\n", 39);
			return (0);
		}
		if (token->prev->type == PIPE || token->next->type == PIPE)
		{
			write(2, "syntax error near unexpected token `|'\n", 39);
			return (0);
		}
	}
	if (is_redirection(token->type)
		&& (!token->next || token->next->type != WORD))
	{
		write(2, "syntax error near unexpected token `newline'\n", 45);
		return (0);
	}
	return (1);
}

int	check_grammar(t_token_list *head)
{
	t_token_list	*token;

	if (!head)
		return (0);
	token = head;
	while (token)
	{
		if (!check_token(token))
			return (0);
		token = token->next;
	}
	return (1);
}
