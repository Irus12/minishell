/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:16:10 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/10 15:13:14 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	x;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = start;
	x = 0;
	while (s[i] && x < len)
	{
		out[x] = (char) s[i];
		i++;
		x++;
	}
	out[x] = '\0';
	return (out);
}
