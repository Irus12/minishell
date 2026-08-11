/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:25:57 by nschilli          #+#    #+#             */
/*   Updated: 2026/02/02 06:48:49 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthex_upp(const unsigned int nbr)
{
	int	length;
	int	rmdr;

	length = 0;
	rmdr = nbr % 16;
	if (nbr >= 16)
		length += ft_puthex_upp(nbr / 16);
	if (rmdr < 10)
		ft_putchar(rmdr + '0');
	else
		ft_putchar(rmdr - 10 + 'A');
	return (length + 1);
}
