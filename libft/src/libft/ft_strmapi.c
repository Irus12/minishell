/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:15:34 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 15:15:36 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*out;

	i = 0;
	out = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (s[i])
	{
		out[i] = (*f)(i, (char) s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
