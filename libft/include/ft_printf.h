/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 22:22:12 by nschilli          #+#    #+#             */
/*   Updated: 2026/05/26 01:00:02 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
size_t	ft_print_adress(void *adress);
size_t	ft_putchar(char c);
size_t	ft_puthex_low(unsigned int n);
size_t	ft_puthex_upp(unsigned int n);
size_t	ft_putnbr(int n);
size_t	ft_putstr(char *str);
size_t	ft_putunbr(unsigned int n);

#endif
