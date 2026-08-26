/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:05:08 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 17:11:00 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env_node	*create_node(char *var)
{
	t_env_node	*new_node;
	int			i;

	if (!var)
		return (NULL);
	new_node = malloc(sizeof(t_env_node));
	if (!new_node)
		return (NULL);
	i = 0;
	while (var[i] != '=' && var[i])
		i++;
	new_node->key = ft_strndup(var, i);
	if (var[i] == '=')
		i++;
	new_node->val = ft_strdup(var + i);
	new_node->next = NULL;
	return (new_node);
}

t_env_node	*add_node(t_env *env, t_env_node *node)
{
	t_env_node	*curr;

	if (!env || !node)
		return (NULL);
	if (!env->head)
	{
		env->head = node;
		node->next = NULL;
		return (node);
	}
	curr = env->head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = node;
	node->next = NULL;
	return (node);
}
