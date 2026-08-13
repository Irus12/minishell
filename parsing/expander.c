/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:47:21 by nschilli          #+#    #+#             */
/*   Updated: 2026/08/12 16:54:43 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "minishell.h"

/*
TODO
en soit pour les heredoc EOF :
on expand de base sauf si dans un '$user'
et commen on doit supprimer les EOF on delet ca
après le passage de expanding dans tokenlist

avec str_cmp :
$? = 0
*/
/*
Will expand the found variable if it is not inside a simple quote
*/
/*
static void	process(char *str, char *out, char *var, int *index)
{
	char	in_quote;

	in_quote = 0;
	while (str[*index])
	{
		if (in_quote == '\'')
			in_quote = 0;
		if (str[*index] == '\'' && quote_can_be_closed(str, '\''))
			in_quote = '\'';
		if (str[*index] == '$' && in_quote == 0)
		{
			var = word_extractor(str + *index, word_len(str + *index));
			if (getenv(var + 1) == NULL)
				str_append(&out, "");
			else
				str_append(&out, getenv(var + 1));
			*index += ft_strlen(var);
			free(var);
			continue ;
		}
		str_append_char(&out, str[*index++]);
	}
}
*/

/*
TODO
besoin de ft_strcmp
*/
static void	expand_str(char **var, char **str, char **out, int *index)
{
	*var = word_extractor(*str + *index, word_len(*str + *index));
	if(!ft_strncmp(*var, "$?", ft_strlen(*var)))
		str_append(&(*out), "TODO"); //TODO
	else if (getenv(*var + 1) != NULL)
		str_append(&(*out), getenv(*var + 1));
	*index += ft_strlen(*var);
	free(*var);
}

static void	assign_skip(char *s, char assign, int *index)
{
	*s = assign;
	(*index)++;
}

/*
Expand a string if it's possible
won't expand variable in simple quotes like '$VAR'
won't consider EOF edgecase
*/
char	*string_expander(char *str)
{
	char	in_quote;
	char	*out;
	char	*var;
	int		i;

	in_quote = 0;
	out = ft_strdup(""); //FT
	i = 0;
	while (str[i])
	{
		if (in_quote == 0 && str[i] == '\'' && quote_can_be_closed(str, '\'')) // si simple on skip le getenv
			assign_skip(&in_quote, '\'', &i);
		else if (in_quote == '\'' && str[i] == '\'')
			assign_skip(&in_quote, 0, &i);
		else if (str[i] == '$' && in_quote == 0)
			expand_str(&var, &str, &out, &i);
		else
			str_append_char(&out, str[i++]);
	}
	return (out);
}

/*
EOF handling

expand : 
<< EOF ..... EOF
<< VAR

ducoup si le EOF est quoted je peux just dire de pas expand
*/

void	list_expander(t_token_list **tkn)
{
	t_token_list	*node;
	char			*expanded;

	node = *tkn;
	while (node)
	{
		if (node->type == WORD)
		{
			expanded = string_expander(node->str);
			free(node->str);
			node->str = expanded;
		}
		node = node->next;
	}
}
