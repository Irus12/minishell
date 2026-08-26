/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:22:53 by romeo             #+#    #+#             */
/*   Updated: 2025/10/24 16:17:20 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_itoa(int n)
{
	int		c;
	long	nl;

	nl = n;
	c = 1;
	if (nl < 0)
	{
		c++;
		nl = -nl;
	}
	while (nl >= 10)
	{
		nl = nl / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		size;
	long	number;
	int		i;

	size = count_itoa(n);
	itoa = (char *)malloc((size + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	i = 0;
	number = n;
	if (number < 0)
	{
		itoa[0] = '-';
		i = 1;
		number = -number;
	}
	itoa[size] = '\0';
	while (size > i)
	{
		itoa[size - 1] = (number % 10) + '0';
		number = number / 10;
		size--;
	}
	return (itoa);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s", ft_itoa(-123));
// }
