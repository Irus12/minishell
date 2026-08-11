/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:15:14 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 21:11:57 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *c, size_t max)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		if (i >= max)
			return (max);
		i++;
	}
	return (i);
}

/*
size is the maximum length of the finally built string
dlen is the amount of existing characters in the buffer limited by the size
parameter
" char dst[20] = "Hello"; ", size is 20 and dlen will be 5

"if (dlen < size)" checks if there's at least 1 byte left of the \0
"(size - dlen - 1)" is the amount of writable space left
*/
size_t	ft_strlcat(char *dst, const char *str, size_t size)
{
	size_t	dlen;
	size_t	i;

	dlen = ft_strnlen(dst, (int)size);
	i = 0;
	if (dlen < size)
	{
		while (str[i] && i < (size - dlen - 1))
		{
			dst[dlen + i] = (char)str[i];
			i++;
		}
		dst[dlen + i] = '\0';
	}
	return (dlen + ft_strlen((char *) str));
}
