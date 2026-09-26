/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:14:33 by romeo             #+#    #+#             */
/*   Updated: 2026/09/27 00:57:50 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	invalid_quotes(char *str)
{
	char	in_quote;
	int		i;

	i = 0;
	in_quote = 0;
	while (str[i])
	{
		if (in_quote && str[i] == in_quote)
			in_quote = 0;
		else if (in_quote == 0 && (str[i] == '\'' || str[i] == '"'))
			in_quote = str[i];
		i++;
	}
	return (in_quote);
}

static int	is_redirection(t_token type)
{
	return (type == TRUNCATE || type == APPEND
		|| type == REDIRECT_INPUT || type == HEREDOC);
}

static int	check_token(t_token_list *token)
{
	if (invalid_quotes(token->str))
		{
			write(2, "syntax error invalid quote combination\n", 39); //meilleur msg ?
			return (0);
		}
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
