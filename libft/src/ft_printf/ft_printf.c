/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:42:15 by nschilli          #+#    #+#             */
/*   Updated: 2026/02/03 12:55:49 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h> 
#include "ft_printf.h"

/*
returns -1 if an invalid % command is found
TODO decimal
last check for str[i + 2] to avoid segfault
*/
static int	filler_detector(char *str, size_t index, va_list args)
{
	if (str[index + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[index + 1] == 'd' || str[index + 1] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (str[index + 1] == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (str[index + 1] == 'x')
		return (ft_puthex_low(va_arg(args, int)));
	else if (str[index + 1] == 'X')
		return (ft_puthex_upp(va_arg(args, int)));
	else if (str[index + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str[index + 1] == 'p')
		return (ft_print_adress(va_arg(args, void *)));
	else if (str[index + 1] == '%')
		return (ft_putchar('%'));
	else if (str[index + 1] && str[index + 2])
		return (ft_putchar(str[index]) + ft_putchar(str[index + 1]));
	else
		return (-1);
}

/*
i+=2 to skip the % and the filler char 
*/
int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		printed_chars;
	int		word_len;

	i = 0;
	printed_chars = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			word_len = filler_detector((char *)str, i, args);
			if (word_len == -1)
				return (-1);
			printed_chars += word_len;
			i += 2;
		}
		else
			printed_chars += ft_putchar(str[i++]);
	}
	va_end(args);
	return (printed_chars);
}
