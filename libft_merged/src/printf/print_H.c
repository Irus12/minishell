/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_H.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:51:31 by romeo             #+#    #+#             */
/*   Updated: 2026/02/03 19:10:48 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	print_hh(va_list ap)
{
	unsigned int	value;

	value = va_arg(ap, unsigned int);
	ft_put_nbr_base(value, "0123456789ABCDEF");
	return (size_hex(value));
}
