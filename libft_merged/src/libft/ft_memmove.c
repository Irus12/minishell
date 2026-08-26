/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:36:39 by romeo             #+#    #+#             */
/*   Updated: 2025/10/24 16:20:45 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*og_dest;

	og_dest = dest;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n)
		{
			n--;
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
		}
	}
	else
	{
		while (n)
		{
			*(unsigned char *)dest = *(unsigned char *)src;
			dest++;
			src++;
			n--;
		}
	}
	return (og_dest);
}
