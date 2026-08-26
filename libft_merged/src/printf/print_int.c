/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:27:09 by romeo             #+#    #+#             */
/*   Updated: 2026/02/03 19:10:48 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	print_nbr(int n)
{
	int	written;

	written = 1;
	if (n < 0)
		written++;
	ft_putnbr_fd(n, 1);
	while (-10 >= n || n >= 10)
	{
		written++;
		n /= 10;
	}
	return (written);
}

int	print_int(va_list ap)
{
	int	nb;

	nb = va_arg(ap, int);
	return (print_nbr(nb));
}
