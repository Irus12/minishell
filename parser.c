/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:17:06 by nschilli          #+#    #+#             */
/*   Updated: 2026/08/31 17:15:13 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void	free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_token_list	*parser(char *str)
{
	char			**lexlings;
	t_token_list	*tokens;
	int	size;

	tokens = NULL;
	size = 0;
	lexlings = lexer_tab(str);
	while(lexlings[size])
		size++;
	list_init(&tokens, lexlings, size);
	list_expander(&tokens);
	free_double_tab(lexlings);
	list_quotes_cleaner(tokens);
	//void	list_quote_cleaner(t_token_list *head)
	return (tokens);
}

*/