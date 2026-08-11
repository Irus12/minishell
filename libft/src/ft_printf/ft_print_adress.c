/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:28:14 by nschilli          #+#    #+#             */
/*   Updated: 2026/02/02 06:48:06 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
+2 for the "0x"
*/
size_t	printer(const unsigned long nbr)
{
	int	length;
	int	rmdr;

	length = 0;
	rmdr = nbr % 16;
	if (nbr >= 16)
		length += printer(nbr / 16);
	if (rmdr < 10)
		ft_putchar(rmdr + '0');
	else
		ft_putchar(rmdr - 10 + 'a');
	return (length + 1);
}

size_t	ft_print_adress(void *adress)
{
	size_t	length;

	length = 0;
	if (adress == NULL)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	length = printer((const unsigned long)adress);
	return (length + 2);
}
