/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:41:48 by nschilli          #+#    #+#             */
/*   Updated: 2026/02/02 18:16:31 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

size_t	ft_putnbr(int n)
{
	size_t	length;
	long	nbr;

	length = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
		length++;
	}
	if (0 <= nbr && nbr <= 9)
	{
		length += ft_putchar(nbr + '0');
	}
	else
	{
		length += ft_putnbr(nbr / 10);
		length += ft_putchar((nbr % 10) + '0');
	}
	return (length);
}
