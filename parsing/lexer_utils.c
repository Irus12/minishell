/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:58:12 by nschilli          #+#    #+#             */
/*   Updated: 2026/08/12 19:10:07 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//check if malloc too big
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
			i++; //on copie plus la closing quote
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
quand on est dans une quote "" on doit copier les ' et vice versa
(normalement ca marche)

Si on est hors quote → copie le caractère normalement
Si on voit une quote ouvrante → entre en mode quote, ne copie pas la quote elle-même
Si on est en quote → copie tout
Si on voit la quote fermante → sort du mode quote,
ne copie pas la quote fermante

j'ai enlever les else if en if et ca a bien marché jsp si faut faire ca avec le no_quote_len()
*/
char *in_quote_extractor(char *str)
{
	char	*line;
	char	in_quote;
	int		i;
	int		j;

	in_quote = 0;
	i = 0;
	j = 0;
	line = malloc((no_quote_len(str) + 1) * sizeof(char));
	while (str[i] == '\0')
	{
		if (!in_quote && (str[i] == '\'' || str[i] == '"'))
			in_quote = str[i++];
		if (in_quote && (str[i] == in_quote))
		{
			i++; //on copie plus la closing quote
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
Returns the number of closing quotes
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

int str_has_closing_quotes(char *str)
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

void	clean_quotes(char **lex)
{
	int	i;

	i = 0;
	while (lex[i])
	{
		if (str_has_closing_quotes(lex[i]))
		{
			lex[i] = in_quote_extractor(lex[i]);
		}
		if ((lex[i][0] == '"' && lex[i][1] == '"')
			|| (lex[i][0] == '\'' && lex[i][1] == '\''))
		{
			free(lex[i]);
			lex[i] = "";
		}
		i++;
	}
}

void	clean_quotes_word(char *word)
{
	int	i;

	i = 0;
	if ((word[0] == '"' && word[1] == '"') || (word[0] == '\'' && word[1] == '\''))
	{
		free(word);
		word = "";
	}
	else
		word = in_quote_extractor(word);
	i++;
}
