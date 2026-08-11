/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:12:56 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 15:12:59 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	sign(char s)
{
	if (s == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		i;
	int		last_sgn;
	int		out;

	str = (char *) nptr;
	i = 0;
	last_sgn = 1;
	out = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		last_sgn = sign(str[i]);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		out = out * 10 + (str[i] - 48);
		i++;
	}
	return (out * last_sgn);
}
