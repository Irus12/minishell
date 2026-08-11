/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:16:02 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 21:35:12 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static int	validchar(char c, char *to_rmv)
{
	size_t	i;

	i = 0;
	while (to_rmv[i])
	{
		if (to_rmv[i] == c)
			return (0);
		i++;
	}
	return (1);
}

/*
"str[*end - 1]" because we dont consider the \0 at index end
"*end > *start" prevents underflow when all characters are trimmed
*/
static size_t	mallength(char *str, char *set, size_t *start, size_t *end)
{
	while (!validchar(str[*start], set) && str[(*start)])
		(*start)++;
	while (!validchar(str[*end - 1], set) && *end > *start)
		(*end)--;
	return (*end - *start);
}

/*
"start" is the index where the first valid letter begins
"end" is the index JUST AFTER the last valid letter ends

"if (len <= 0)" check both if len == 0 and start >= end
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s1);
	len = mallength((char *)s1, (char *)set, &start, &end);
	if (len <= 0)
		return (ft_strdup(""));
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	while (start < end)
		out[i++] = (char) s1[start++];
	out[i] = '\0';
	return (out);
}
