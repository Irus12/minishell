/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:37:42 by romeo             #+#    #+#             */
/*   Updated: 2025/10/24 16:19:16 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	count_splitted(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*write_splitted(const char *string, char c)
{
	char	*new;
	int		size;
	int		count;

	size = 0;
	while (string[size] && string[size] != c)
		size++;
	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	count = 0;
	while (count < size)
	{
		new[count] = string[count];
		count++;
	}
	new[count] = '\0';
	return (new);
}

static int	filling_tab(char **array, const char *string, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (string[i])
	{
		while (string[i] && string[i] == c)
			i++;
		if (!string[i])
			break ;
		array[j] = write_splitted(string + i, c);
		if (!array[j])
		{
			array[j] = NULL;
			free_array(array);
			return (-1);
		}
		j++;
		while (string[i] && string[i] != c)
			i++;
	}
	array[j] = NULL;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;
	int		filled;

	if (!s)
		return (NULL);
	count = count_splitted(s, c);
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	filled = filling_tab(split, s, c);
	if (filled == -1)
		return (NULL);
	return (split);
}

// #include <stdio.h>
// void print_array(char **array)
// {
// 	int	i = 0;
// 	while (array[i])
// 	{
// 		printf("splitted[%d] = _%s_\n", i, array[i]);
// 		i++;
// 	}
// }
//
// int main()
// {
// 	char splitted[] = "00je000suis--0splitted00";
// 	char **new;
// 	new = ft_split(splitted, '0');
// 	printf("after split \n\n");
// 	print_array(new);
// 	free_array(new);
// }
//
//
//
//
//
//
//
//
//
//
//
//
// static void	free_array(char **array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	if (array)
// 		free(array);
// }

// static int	count_splitted(const char *s, char c)
// {
// 	int	count;
// 	int	i;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		if (s[i] && s[i] != c)
// 			count++;
// 		while (s[i] && s[i] != c)
// 			i++;
// 		while (s[i] && s[i] == c)
// 			i++;
// 	}
// 	return (count);
// }

// static char	*write_splitted(const char *string, char c)
// {
// 	char	*new;
// 	int		size;
// 	int		count;

// 	size = 0;
// 	while (string[size] && string[size] != c)
// 		size++;
// 	new = (char *)malloc(sizeof(char) * (size + 1));
// 	if (!new)
// 		return (NULL);
// 	count = 0;
// 	while (count < size)
// 	{
// 		new[count] = string[count];
// 		count++;
// 	}
// 	new[count] = '\0';
// 	return (new);
// }

// static int	filling_tab(char **array, const char *string, char c)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (*string && *string == c)
// 		string++;
// 	while (string[i] && string[i] != c)
// 	{
// 		array[j] = write_splitted(string + i, c);
// 		if (!array[j])
// 		{
// 			free_array(array);
// 			return (-1);
// 		}
// 		j++;
// 		while (string[i] && string[i] != c)
// 			i++;
// 		while (string[i] && string[i] == c)
// 			i++;
// 	}
// 	return (1);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**split;
// 	int		count;

// 	if (!s)
// 		return (NULL);
// 	count = count_splitted(s, c);
// 	split = (char **)malloc(sizeof(char *) * (count + 1));
// 	if (!split)
// 		return (NULL);
// 	if (filling_tab(split, s, c) == -1)
// 		return (NULL);
// 	split[count] = NULL;
// 	return (split);
// }