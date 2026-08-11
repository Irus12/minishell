/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:15:50 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 15:15:52 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*ndl;
	size_t	i;
	size_t	j;

	hay = (char *)haystack;
	ndl = (char *)needle;
	i = 0;
	j = 0;
	if (!*needle)
		return ((char *) haystack);
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == ndl[j] && haystack [i + j] && (i + j) < len)
			j++;
		if (ndl[j] == '\0')
			return (hay + i);
		i++;
	}
	return (0);
}
