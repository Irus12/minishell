/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:14:54 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 15:14:55 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*out;

	len = ft_strlen(str);
	i = 0;
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (str[i])
	{
		out[i] = (char)str[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
