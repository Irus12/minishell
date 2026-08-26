/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:42:03 by romeo             #+#    #+#             */
/*   Updated: 2026/02/03 19:10:48 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	ft_put_uint_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_put_uint_fd(n / 10, fd);
		ft_put_uint_fd(n % 10, fd);
	}
	if (n <= 9)
		ft_putchar_fd((n + '0'), fd);
}

static int	print_unbr(unsigned int n)
{
	int	written;

	written = 1;
	ft_put_uint_fd(n, 1);
	while (n >= 10)
	{
		written++;
		n /= 10;
	}
	return (written);
}

int	print_unsigned_int(va_list ap)
{
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	return (print_unbr(nb));
}
