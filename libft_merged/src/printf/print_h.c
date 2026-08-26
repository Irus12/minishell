/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:09:27 by romeo             #+#    #+#             */
/*   Updated: 2026/02/03 19:10:48 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	print_h(va_list ap)
{
	unsigned int	value;

	value = va_arg(ap, unsigned int);
	ft_put_nbr_base(value, "0123456789abcdef");
	return (size_hex(value));
}
