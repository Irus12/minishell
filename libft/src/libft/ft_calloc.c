/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:45:13 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 19:13:33 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;
	size_t	length;

	length = nmemb * size;
	out = (void *)malloc(length);
	if (!out)
		return (NULL);
	ft_bzero(out, length);
	return (out);
}
