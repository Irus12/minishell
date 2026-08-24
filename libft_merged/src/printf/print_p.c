/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:52:53 by romeo             #+#    #+#             */
/*   Updated: 2026/02/03 19:10:48 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	print_p(va_list ap)
{
	unsigned long	addr;

	addr = (unsigned long)va_arg(ap, void *);
	if (!addr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	write(1, "0x", 2);
	ft_put_nbr_base(addr, "0123456789abcdef");
	return (2 + size_hex(addr));
}
