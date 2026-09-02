/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:56:37 by nschilli          #+#    #+#             */
/*   Updated: 2026/08/31 17:55:28 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Will inspect the string of an env variable
and will give it's length (without the $)
*/
int	token_len(char *str)
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
Will append/concat a string at the end of an another string
*/
void	str_append(char **str, char *to_add)
{
	int		total;
	int		slen;
	int		i;
	int		j;
	char	*out;

	i = 0;
	j = 0;
	slen = ft_strlen(*str);
	total = slen + ft_strlen(to_add);
	out = malloc((total + 1) * sizeof(char));
	while (i < slen)
		out[i++] = (*str)[j++];
	j = 0;
	while (i < total)
		out[i++] = to_add[j++];
	out[i] = '\0';
	free(*str);
	*str = out;
}

/*
Will append/concat a character at the end of a string
*/
void	str_append_char(char **str, char c)
{
	char	*tmp;

	tmp = malloc(2 * sizeof(char));
	tmp[0] = c;
	tmp[1] = '\0';
	str_append(str, tmp);
	free(tmp);
}

/*
Returns 1 if an EOF string is found
*/
int	has_eof_delimiter(t_token_list *tkn) //DEPRICATED
{
	int				count;

	while (tkn)
	{
		if (ft_strncmp(tkn->str, "EOF", 3))
			count++;
		if (count >= 2)
			return (1);
		tkn = tkn -> next;
	}
	return (0);
}
