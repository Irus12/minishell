/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:14:35 by nschilli          #+#    #+#             */
/*   Updated: 2025/11/03 20:04:21 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	allfree(char **tab, size_t max)
{
	size_t	i;

	i = 0;
	while (i < max)
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

/*
(str[i] == sep && i > 0 && str[i - 1] != sep)
detects when we exit a word
We encounter a separator while the previous character was a word

(str[i + 1] == '\0' && letter_cnt > 0)
detects when it's the end of a word

in both condition it allocates the right amount to the sub-array

Stops and returns -1 if the allocation fails, otherwise return 0
*/
static int	setupmalloc(char **tab, char *str, char sep)
{
	size_t	current_wrd;
	size_t	letter_cnt;
	size_t	i;

	current_wrd = 0;
	letter_cnt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
			letter_cnt++;
		if ((str[i] == sep && i > 0 && str[i - 1] != sep)
			|| (str[i + 1] == '\0' && letter_cnt > 0))
		{
			tab[current_wrd] = malloc((sizeof(char)) * (letter_cnt + 1));
			if (!tab[current_wrd])
				return (allfree(tab, current_wrd), -1);
			current_wrd++;
			letter_cnt = 0;
		}
		i++;
	}
	return (0);
}

/*
(i > 0 && str[i - 1] != sep)
switch to the next sub-array if a sep is detected

if (y > 0)
here to manage the last the last \0 
other methods makes it hard to read
*/
static void	building(char **tab, char *str, char sep)
{
	size_t	x;
	size_t	y;
	size_t	i;

	x = 0;
	y = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			tab[x][y] = str[i];
			y++;
		}
		else if (i > 0 && str[i - 1] != sep)
		{
			tab[x][y] = '\0';
			x++;
			y = 0;
		}
		i++;
	}
	if (y > 0)
		tab[x][y] = '\0';
}

/*
last_is_sep, (OG idea scrapped in other fct because of length)
flag that tells if last char is a separator

(str[i] != sep && last_is_sep)
we are inside a word so we count the letters
*/
static size_t	wordscounter(char *str, char sep)
{
	size_t	i;
	size_t	cnt;
	size_t	last_is_sep;

	i = 0;
	cnt = 0;
	last_is_sep = 1;
	while (str[i])
	{
		if (str[i] != sep && last_is_sep)
		{
			cnt++;
			last_is_sep = 0;
		}
		else if (str[i] == sep)
			last_is_sep = 1;
		i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nbrwords;

	if (!s)
		return (NULL);
	nbrwords = wordscounter((char *) s, c);
	tab = malloc(sizeof(char *) * (nbrwords + 1));
	if (!tab)
		return (NULL);
	if (setupmalloc(tab, (char *) s, c) == -1)
		return (NULL);
	building(tab, (char *) s, c);
	tab[nbrwords] = NULL;
	return (tab);
}
