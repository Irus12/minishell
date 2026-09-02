/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:00:27 by romeo             #+#    #+#             */
/*   Updated: 2026/09/01 19:04:00 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_export(t_shell *shell, char **execs)
{
	int	i;

	if (!execs[1])
		exp_no_args(shell->environ);
	else
	{
		i = 1;
		while (execs[i])
		{
			exporting(shell, execs[i]);
			i++;
		}
	}
}

static int	count_env_size(t_env *env)
{
	t_env_node	*node;
	int			size;

	size = 0;
	node = env->head;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

char	**env_to_arr(t_env *env)
{
	int				size;
	char			**env_arr;
	t_env_node		*node;
	int				i;

	size = count_env_size(env);
	env_arr = malloc(sizeof(char *) * (size + 1));
	if (!env_arr)
		return (NULL);
	node = env->head;
	i = 0;
	while (node)
	{
		env_arr[i] = ft_strjoin(node->key, "=");
		env_arr[i] = ft_strjoin(env_arr[i], node->val);
		i++;
		node = node->next;
	}
	env_arr[i] = NULL;
	return (env_arr);
}

static void	exec_in_child(char **cmd, char **env_arr, t_shell *shell)
{
	if (execve(cmd[0], cmd, env_arr) == -1)
	{
		perror("execve");
		free_tab(env_arr);
		shell->exit_status = 126;
		exit(126);
	}
}

void	ft_mshell(t_shell *shell, char **cmd)
{
	int			status;
	pid_t		pid;
	char		**env_arr;

	if (access(cmd[0], F_OK) == -1)
	{
		printf("minishell: command not found\n");
		free_tab(cmd);
		shell->exit_status = 127;
		return ;
	}
	env_arr = env_to_arr(shell->environ);
	if (!env_arr)
		return ;
	pid = fork();
	safe_pid(pid);
	if (pid == 0)
		exec_in_child(cmd, env_arr, shell);
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			shell->exit_status = WEXITSTATUS(status); //HERE GET ExiT
		}
	}
	free_tab(env_arr);
}
