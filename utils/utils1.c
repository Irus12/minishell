/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:23:09 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 16:37:41 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strndup(char *s, int i)
{
	char	*dup;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len > i)
		len = i;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strncpy(dup, s, len);
	dup[len] = '\0';
	return (dup);
}

char	*ft_strncpy(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while (s2[i] && i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < len)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}

void	free_env(t_env *env)
{
	t_env_node	*current;
	t_env_node	*temp;

	current = env->head;
	while (current)
	{
		temp = current;
		current = current->next;
		node_free(temp);
	}
	free(env);
}

int	is_valid(char *arg)
{
	int	i;

	i = 0;
	if (!arg || (!ft_isalpha(arg[i]) && arg[i] != '_'))
		return (0);
	i++;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
