/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:13:13 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/10 15:24:53 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int	nbrdigits(long c)
{
	int	digits;

	digits = 0;
	if (c < 0)
		c *= -1;
	if (c == 0)
		return (1);
	while (c >= 1)
	{
		c /= 10;
		digits++;
	}
	return (digits);
}

static void	building(char *tab, long nbr, int ndgt, int shift)
{
	tab[ndgt + shift] = '\0';
	ndgt--;
	while (ndgt >= 0)
	{
		tab[ndgt + shift] = (nbr % 10) + '0';
		nbr /= 10;
		ndgt --;
	}
	if (shift)
		tab[0] = '-';
}

char	*ft_itoa(int c)
{
	char	*out;
	int		digits;
	int		shift;
	long	nbr;

	nbr = c;
	shift = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		shift = 1;
	}
	digits = nbrdigits(nbr);
	out = malloc((digits + 1 + shift) * sizeof(char));
	if (!out)
		return (NULL);
	building(out, nbr, digits, shift);
	return (out);
}
