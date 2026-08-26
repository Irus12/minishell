/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:01:32 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 17:07:13 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	equal_pos(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	return (i);
}

void	existing_node(t_env_node *node, char *arg, int pos)
{
	if (arg[pos] == '=')
	{
		free(node->val);
		node->val = ft_strdup(arg + pos + 1);
	}
}

char	*ext_key(char *str, int *pos)
{
	if (!str || !is_valid_id(str))
		return (NULL);
	*pos = equal_pos(str);
	return (ft_strndup(str, *pos));
}

void	new_node2(t_env *env, char *key, char *arg, int pos)
{
	t_env_node	*node;

	node = malloc(sizeof(t_env_node));
	if (!node)
	{
		free(key);
		return ;
	}
	node->key = key;
	if (arg[pos] == '=')
		node->val = ft_strdup(arg + pos + 1);
	else
		node->val = NULL;
	node->next = NULL;
	if (!add_node(env, node))
		node_free(node);
}

int	exp_no_args(t_env *env)
{
	t_pair	*pairs;
	int		count;

	if (!env || !env->head)
		return (0);
	count = count_env_nodes(env);
	pairs = create_env_array(env, count);
	if (!pairs)
		return (0);
	sort_env_array(pairs, count);
	print_env_array(pairs, count);
	free_env_arr(pairs, count);
	return (1);
}
