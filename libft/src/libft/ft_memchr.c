/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:13:25 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 15:13:28 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (mem[i] == (unsigned char) c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
