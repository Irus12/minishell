/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 02:05:02 by nschilli          #+#    #+#             */
/*   Updated: 2025/10/22 02:05:09 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t n)
{
	char	*t;
	size_t	i;

	t = (char *)src;
	i = 0;
	while (i < n)
	{
		t[i] = c;
		i++;
	}
	return (src);
}
