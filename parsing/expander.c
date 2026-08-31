/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:47:21 by nschilli          #+#    #+#             */
/*   Updated: 2026/08/31 16:19:34 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "minishell.h"

/*
Will expand the found variable if it is not inside a simple quote
We use a system of string append/concat to rewrite the token's string
in order to expand an env value ($VAR)
*/

/*
Will inspect the string of an env variable
and will give it's length (without the $)
*/
static int	token_len(char *str)
{
	int	len;

	len = 1;
	if (str[len] == '?' || str[len] == '$')
		return (2);
	while (str[len] && (ft_isalnum(str[len]) || str[len] == '_'))
		len++;
	return (len);
}


/*
(due to space limitation) this function is used 
by string_expander() in cases where a env variable is 
detected and needs to be expanded
*/
static void	expand_str(char **str, char **out, int *index)
{
	char *var;

	var = word_extractor(*str + *index, token_len(*str + *index)); //ici il faut tweak 
	if(!ft_strncmp(var, "$?", ft_strlen(var)))
		str_append(&(*out), ft_itoa(*get_status())); //TODO
	else if (getenv(var + 1) != NULL)
		str_append(&(*out), getenv(var + 1));
	*index += ft_strlen(var);
	free(var);
}

/*
(due to space limitation) this function is used 
by string_expander() in cases where we are inside 
a single quote, it adds the characters end assign accordingly
the in_quote variable
*/
static void	assign_skip(char *receiver, char assign, int *index, t_expand_state *state)
{
	str_append_char(&state->new_str, state->og_str[*index]);
	*receiver = assign;
	(*index)++;
}

/*
Expand a string if it's possible and
won't expand env variables in simple quotes like '$VAR'
*/
char	*string_expander(char *str)
{
	t_expand_state	state;
	char	in_quote;
	int		i;

	state.new_str = ft_strdup("");
	state.og_str = str;
	in_quote = 0;
	i = 0;
	while (str[i])
	{
		if (in_quote == 0 && state.og_str[i] == '\'' && quote_can_be_closed(state.og_str, '\'')) // si simple on skip le getenv
			assign_skip(&in_quote, '\'', &i, &state);
		else if (in_quote == '\'' && state.og_str[i] == '\'')
			assign_skip(&in_quote, 0, &i, &state);
		else if (state.og_str[i] == '$' && in_quote == 0)
			expand_str(&state.og_str, &state.new_str, &i);
		else
			str_append_char(&state.new_str, state.og_str[i++]);
	}
	return (state.new_str);
}

/*
takes a t_token_list and will try to expand env variables
inside of found string if possible.
Won't expand env variables in simple quotes like '$VAR'
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
