/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:38:43 by romeo             #+#    #+#             */
/*   Updated: 2026/08/26 01:49:57 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_id(char *arg)
{
	if (!is_valid(arg))
	{
		printf("export: `%s': not a valid identifier\n", arg);
		return (0);
	}
	return (1);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len_s1 + 1);
	ft_strlcpy(res + len_s1, s2, len_s2 + 1);
	res[len_s1 + len_s2] = 0;
	return (res);
}

int	create_add(t_shell *shell, char *args)
{
	t_env_node	*node;
	t_env		*env;

	env = shell->environ;
	node = malloc(sizeof(t_env_node));
	if (!node || !ext_val(args, node))
	{
		node_free(node);
		return (0);
	}
	if (!add_node(env, node))
	{
		node_free(node);
		return (0);
	}
	return (1);
}

t_env_node	*get_node(t_env *env, char *key)
{
	t_env_node	*curr;

	if (!env || !key)
		return (NULL);
	curr = env->head;
	while (curr)
	{
		if (ft_strcmp(curr->key, key) == 0)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}


int	ext_val(char *arg, t_env_node *node)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i] != '=')
		i++;
	node->key = ft_strndup(arg, i);
	if (arg[i] == '=')
		i++;
	node->val = ft_strdup(arg + i);
	if (arg[i] == '=' && !node->val)
	{
		free(node->key);
		return (0);
	}
	return (1);
}

// void	free_env(t_env *env)
// {
// 	t_env_node	*current;
// 	t_env_node	*temp;

// 	current = env->head;
// 	while (current)
// 	{
// 		temp = current;
// 		current = current->next;
// 		node_free(temp);
// 	}
// 	free(env);
// }
