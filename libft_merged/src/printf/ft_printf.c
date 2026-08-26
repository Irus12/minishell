/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:57:37 by romeo             #+#    #+#             */
/*   Updated: 2026/02/03 19:10:48 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_proceed(char c, va_list ap)
{
	if (c == 's')
		return (print_s(ap));
	else if (c == 'c')
		return (print_c(ap));
	else if (c == 'd' || c == 'i')
		return (print_int(ap));
	else if (c == 'u')
		return (print_unsigned_int(ap));
	else if (c == 'p')
		return (print_p(ap));
	else if (c == 'x')
		return (print_h(ap));
	else if (c == 'X')
		return (print_hh(ap));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		return_check;
	int		chr_printed;

	va_start(ap, input);
	return_check = 1;
	chr_printed = 0;
	while (*input)
	{
		if (*input != '%')
		{
			write(1, input, 1);
			chr_printed++;
		}
		else if (*input == '%')
		{
			return_check = ft_proceed(*(++input), ap);
			if (return_check == -1)
				return (-1);
			chr_printed += return_check;
		}
		input++;
	}
	va_end(ap);
	return (chr_printed);
}
