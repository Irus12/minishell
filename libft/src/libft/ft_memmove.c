/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:13:52 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 19:25:19 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Critical cases when there's parameter like 'tab' and 'tab + 2'
We compare where the memory adress of cdest and crsc starts, not their length
if cdest is stored after crsc then we copy csrc from the end, otherwise from
the begining
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;
	size_t	i;
	int		param;

	cdest = (char *) dest;
	csrc = (char *) src;
	i = 0;
	param = 1;
	if (!cdest && !csrc)
		return (NULL);
	if (cdest > csrc)
	{
		i = n - 1;
		param = -1;
	}
	while (n--)
	{
		cdest[i] = csrc[i];
		i = i + param;
	}
	return (dest);
}
