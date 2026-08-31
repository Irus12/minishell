/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 00:12:38 by nschilli          #+#    #+#             */
/*   Updated: 2026/08/24 15:34:25 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
The role of the lexing processe is to split the command line (a string)
into multiple strings where each word is stored in a double char array
Each words will be assigned by tokens later on in token.c
*/

/*
Cannot begin with a space
must begin with the first letter or with a (single/double) quote

in the while cycle we check
1. si on est dans la quote
2. si la quote se termine
3. on sort car on a finit le token

|,<,<<,> and >> are at the same time separators and tokens
meanwhile space ' ' is only a separator
*/
int	word_len(char *str)
{
	char	quote;
	int		len;

	quote = 0;
	len = 0;
	if ((str[0] == '<' && str[1] == '<') || (str[0] == '>' && str[1] == '>'))
		return (2);
	else if (str[0] == '|' || str[0] == '<' || str[0] == '>')
		return (1);
	while (str[len])
	{
		if (!quote && (str[len] == '"' || str[len] == '\''))
		{
			//if (len == 0 || str[len - 1] == ' ') //règle les "c'est" mais casse "hello"' 'world
			if (quote_can_be_closed(str, str[len]))
				quote = str[len];
		}
		else if (quote && str[len] == quote)
			quote = 0;
		else if (!quote && (str[len] == ' ' || str[len] == '|'
				|| str[len] == '<' || str[len] == '>'))
			break ;
		len++;
	}
	return (len);
}

/*
We jump from token to token and skip the spaces
We do "str + i" because it's the begining adress of the new token
*/
int	count_tokens(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		count++;
		i += word_len(str + i);
	}
	return (count);
}

/*
will return the first token available from the str adress
must begin with a non space char
*/
char	*word_extractor(char *str, int size)
{
	char	*out;
	int		i;

	out = malloc(size * sizeof(char) + 1);
	i = 0;
	while (i < size)
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

static void	filler(char **tab, char *str)
{
	int	i;
	int	tkn;

	i = 0;
	tkn = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		tab[tkn] = word_extractor(str + i, word_len(str + i));
		i += word_len(str + i);
		tkn++;
	}
}

/*
Generaly used to free a double array of char,
Assumes that NULL is at the last index otherwise SEGFAULT
*/
void	free_lexer_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

/*
Gives an array containing every word from the original string,
symbols such as HEREDOC, REDIRECT_INPUT, PIPE.... etc 
count as a separatorand it's own word
*/
char	**lexer_tab(char *str)
{
	char	**tab;
	int		nbr_token;

	nbr_token = count_tokens(str);
	tab = malloc((nbr_token + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	filler(tab, str);
	tab[nbr_token] = NULL;
	//free(str);
	return (tab);
}

/*
int main	(int argc, char **argv)
{
	char *strs = argv[1];
	int i = 0;
	char **tokens = lexer_tab(strs);
	clean_quotes(tokens);
	while (tokens[i])
	{
		printf("%s\n", tokens[i]);
		i++;
	}
}
*/