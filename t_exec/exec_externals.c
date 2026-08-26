/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_externals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:41:19 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 16:41:27 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*my_getenv(char *name, t_env *env_list)
{
	t_env_node	*current;

	current = env_list->head;
	while (current != NULL)
	{
		if (ft_strcmp(current->key, name) == 0)
			return (current->val);
		current = (current->next);
	}
	return (NULL);
}

static char	**split_path(t_env *env_list)
{
	char	*path_env;

	path_env = my_getenv("PATH", env_list);
	if (!path_env || ft_strlen(path_env) == 0)
		return (NULL);
	return (ft_split(path_env, ':'));
}

static char	*check_abrel(char *cmd)
{
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
	}
	return (NULL);
}

static char	*find_exec(char **allpath, char *cmd)
{
	int		i;
	char	*path_part;
	char	*exec;

	i = 0;
	while (allpath[i])
	{
		path_part = ft_strjoin2(allpath[i], "/");
		exec = ft_strjoin2(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, t_env *env_list)
{
	char	**allpath;
	char	*resolved_path;

	resolved_path = check_abrel(cmd);
	if (resolved_path)
		return (resolved_path);
	allpath = split_path(env_list);
	if (!allpath)
		return (NULL);
	resolved_path = find_exec(allpath, cmd);
	free_tab(allpath);
	return (resolved_path);
}
