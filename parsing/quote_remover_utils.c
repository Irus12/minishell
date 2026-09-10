/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remover_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:37:23 by nschilli          #+#    #+#             */
/*   Updated: 2026/09/10 15:24:03 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Returns the number of pairs of quotes inside the passed string.
*/
int	str_has_closing_quotes(char *str)
{
	int		i;
	int		count;
	char	in_quote;

	i = 0;
	count = 0;
	in_quote = 0;
	while (str[i])
	{
		if (!in_quote && (str[i] == '\'' || str[i] == '"'))
			in_quote = str[i++];
		if (in_quote && (str[i] == in_quote))
		{
			in_quote = 0;
			count++;
		}
		i++;
	}
	return (count);
}

/*
Remove the pairs of quotes present in a string
"hello" becomes hello
"c'est" becomes c'est
*/
void	clean_quotes_word(char *word)
{
	int	i;

	i = 0;
	if ((word[0] == '"' && word[1] == '"')
		|| (word[0] == '\'' && word[1] == '\''))
	{
		free(word);
		word = "";
	}
	else
		word = in_quote_extractor(word);
	i++;
}

/*
Remove the pairs of quotes present in the string of all possible tokens
"hello" becomes hello
"c'est" becomes c'est
*/
void	list_quote_cleaner(t_token_list *head)
{
	while (head)
	{
		if (str_has_closing_quotes(head->str))
		{
			head->str = in_quote_extractor(head->str);
		}
		else if ((head->str[0] == '"' && head->str[1] == '"')
			|| (head->str[0] == '\'' && head->str[1] == '\''))
		{
			free(head->str);
			head->str = ft_strdup("");
		}
		head = head->next;
	}
}
