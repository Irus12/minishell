/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:34:24 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 21:40:08 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*
"if ((char)c == '\0')" checks if the last char is the right one
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	size_t	i;

	i = 0;
	last = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			last = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (last);
}
