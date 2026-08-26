/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:35:45 by romeo             #+#    #+#             */
/*   Updated: 2025/10/24 16:20:45 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_set(set, s1[start]))
		start++;
	while (end > start && is_set(set, s1[end - 1]))
		end--;
	s2 = malloc((end - start + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1 + start, end - start + 1);
	return (s2);
}

// #include <stdio.h>
// int main()
// {
// 	char dab[] = "Ma0MpaMc0 ";
// 	char oui[] = "M0";
// 	printf("%s", ft_strtrim(dab, oui));
// 	return (0);
// }
