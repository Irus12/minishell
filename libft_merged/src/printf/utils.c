/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:20:31 by romeo             #+#    #+#             */
/*   Updated: 2026/02/03 19:10:48 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	size_hex(unsigned long nbr)
{
	int	len;

	len = 1;
	while (nbr / 16 != 0)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

void	ft_put_nbr_base(unsigned long nbr, char *base)
{
	unsigned long	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
	{
		ft_put_nbr_base(nbr / base_len, base);
		ft_put_nbr_base(nbr % base_len, base);
	}
	else
		ft_putchar_fd(base[nbr], 1);
}
