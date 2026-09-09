/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:36:56 by romeo             #+#    #+#             */
/*   Updated: 2026/09/09 18:22:06 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	env_count(t_env *env)
{
	t_env_node	*node;
	int			count;

	count = 0;
	node = env->head;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

static char	*env_line(t_env_node *node)
{
	char	*tmp;
	char	*line;

	tmp = ft_strjoin(node->key, "=");
	if (!tmp)
		return (NULL);
	line = ft_strjoin(tmp, node->val);
	free(tmp);
	return (line);
}

void	free_envp(char **envp)
{
	int	i;

	if (!envp)
		return ;
	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

char	**env_to_envp(t_env *env)
{
	t_env_node	*node;
	char		**envp;
	int			i;

	envp = malloc(sizeof(char *) * (env_count(env) + 1));
	if (!envp)
		return (NULL);
	node = env->head;
	i = 0;
	envp[0] = NULL;
	while (node)
	{
		envp[i] = env_line(node);
		if (!envp[i])
			return (free_envp(envp), NULL);
		i++;
		envp[i] = NULL;
		node = node->next;
	}
	return (envp);
}
