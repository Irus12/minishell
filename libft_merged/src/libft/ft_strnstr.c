/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:47:17 by romeo             #+#    #+#             */
/*   Updated: 2025/10/26 16:41:11 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	nlen;

	if (!*little)
		return ((char *)big);
	nlen = ft_strlen(little);
	i = 0;
	while (i + nlen <= len && big[i])
	{
		if (ft_strncmp(big + i, little, nlen) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
