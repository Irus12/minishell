/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:14:16 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 15:20:49 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (0 <= nbr && nbr <= 9)
	{
		ft_putchar_fd(nbr + '0', fd);
	}
	else
	{
		ft_putnbr_fd((nbr / 10), fd);
		ft_putchar_fd(((nbr % 10) + '0'), fd);
	}
}
