/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:15:08 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 20:04:38 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	building(char *out, char const *s1, char const *s2 )
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		out[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		out[i] = s2[j];
		j++;
		i++;
	}
	out[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	len;

	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	out = malloc(len * sizeof(char));
	if (!out)
		return (NULL);
	building(out, s1, s2);
	return (out);
}
