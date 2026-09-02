/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 19:36:56 by romeo             #+#    #+#             */
/*   Updated: 2026/09/01 02:11:47 by romeo            ###   ########.fr       */
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

static void	handle_exec_error(char *path, t_env *env_list, t_shell *shell)
{
	write(STDERR_FILENO, "Error: Command execution failed\n", 32);
	free(path);
	free_env_list(env_list);
	shell->exit_status = 126;
	exit(126);
}

void	execute_command(t_exec *node, t_env *env_list, t_shell *shell)
{
	char	*resolved_path;
	char	**envp;

	// ft_signal(5, shell);
	if (ft_strchr(node->execs[0], '/'))
	{
		if (access(node->execs[0], F_OK) == -1)
			command_not_found(node->execs[0], shell);
		if (access(node->execs[0], X_OK) == -1)
			exit(126);
	}
	resolved_path = get_path(node->execs[0], env_list);
	if (!resolved_path)
		command_not_found(node->execs[0], shell);
	envp = env_to_envp(env_list);
	if (!envp)
		exit(1);
	if (execve(resolved_path, node->execs, envp) == -1)
	{
		free_envp(envp);
		handle_exec_error(resolved_path, env_list, shell);
	}
}
