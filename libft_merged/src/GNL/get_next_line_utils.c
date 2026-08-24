/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:34:10 by romeo             #+#    #+#             */
/*   Updated: 2026/02/04 00:39:54 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == 0)
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin_free_s1(char *s1, char *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = 0;
	len_s2 = 0;
	if (s1 && *s1)
		len_s1 = ft_strlen_gnl(s1);
	if (s2 && *s2)
		len_s2 = ft_strlen_gnl(s2);
	if ((len_s1 + len_s2) == 0)
		return (NULL);
	res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (NULL);
	ft_strlcpy_gnl(res, s1, len_s1 + 1);
	ft_strlcpy_gnl(res + len_s1, s2, len_s2 + 1);
	res[len_s1 + len_s2] = 0;
	if (s1)
		free (s1);
	return (res);
}
