/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:58:12 by nschilli          #+#    #+#             */
/*   Updated: 2026/09/10 14:39:59 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
gives the length of a string without pairs of quotes
*/
int	no_quote_len(char *str)
{
	char	in_quote;
	int		i;
	int		j;

	in_quote = 0;
	i = 0;
	j = 0;
	while (1)
	{
		if (!in_quote && (str[i] == '\'' || str[i] == '"'))
			in_quote = str[i++];
		if (in_quote && (str[i] == in_quote))
		{
			i++;
			in_quote = 0;
		}
		if (str[i] == '\0')
			break ;
		j++;
		i++;
	}
	return (j);
}

/*
Returns the substring contained inside a quote

if we are outside quotes -> copy the character normaly.
if we have a opening quote -> enter quote mode, copy things
but note the quote itself.
if we are inside a quote (in_quote != 0) -> copy everything.
if we have the closing quote -> close the quote mode
and will not copy the closing quote.

we copy everything and skip the index of things we dont want to copy.
*/
char	*in_quote_extractor(char *str)
{
	char	*line;
	char	in_quote;
	int		i;
	int		j;

	in_quote = 0;
	i = 0;
	j = 0;
	line = malloc((no_quote_len(str) + 1) * sizeof(char));
	while (str[i] != '\0')
	{
		if (!in_quote && (str[i] == '\'' || str[i] == '"'))
			in_quote = str[i++];
		if (in_quote && (str[i] == in_quote))
		{
			i++;
			in_quote = 0;
			continue ;
		}
		line[j++] = str[i++];
	}
	line[j] = '\0';
	free(str);
	return (line);
}

/*
Receive a string and the char of a quote
and check if the quote can be closed.
Returns the number of closing quotes present in a string.
*/
int	quote_can_be_closed(char *str, char quote)
{
	int		i;
	char	in_quote;

	i = 0;
	in_quote = 0;
	while (str[i])
	{
		if (!in_quote && (str[i] == quote))
			in_quote = str[i++];
		if (in_quote && (str[i] == in_quote))
		{
			in_quote = 0;
			return (1);
		}
		i++;
	}
	return (0);
}
