/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:42:04 by romeo             #+#    #+#             */
/*   Updated: 2026/08/20 17:52:30 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_env	*empty_env(t_env *env)
{
	char		cwd[1024];
	t_env_node	*pwd_node;
	t_env_node	*shlvl_node;

	if (!env)
		return (NULL);
	if (!getcwd(cwd, sizeof(cwd)))
	{
		perror("getcwd");
		return (NULL);
	}
	pwd_node = create_node(ft_strjoin("PWD=", cwd));
	if (!pwd_node || !add_node(env, pwd_node))
	{
		node_free(pwd_node);
		return (NULL);
	}
	shlvl_node = create_node("SHLVL=1");
	if (!shlvl_node || !add_node(env, shlvl_node))
	{
		node_free(shlvl_node);
		return (NULL);
	}
	return (env);
}

// static t_env	*empty_env_1(t_env *env)
// {
// 	t_env_node	*node;

// 	node = malloc(sizeof(t_env_node));
// 	if (!node)
// 	{
// 		free(env);
// 		return (NULL);
// 	}
// 	node->key = ft_strdup("PWD");
// 	node->val = getcwd(NULL, 0);
// 	node->next = NULL;
// 	if (!node->key || !node->val)
// 	{
// 		node_free(node);
// 		free(env);
// 		return (NULL);
// 	}
// 	env->head = node;
// 	return (env);
// }

static void	increment_shlvl(t_env *env)
{
	t_env_node		*node;
	int				shlvl;

	node = env->head;
	while (node)
	{
		if (ft_strcmp(node->key, "SHLVL") == 0)
		{
			shlvl = ft_atoi(node->val);
			free(node->val);
			node->val = ft_itoa(shlvl + 1);
			return ;
		}
		node = node->next;
	}
	add_node(env, create_node("SHLVL=1"));
}

t_env	*init_env(char **envp)
{
	t_env		*env;
	t_env_node	*node;
	int			i;

	i = 0;
	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->head = NULL;
	if (!envp || !envp[0])
		return (empty_env(env));
	while (envp[i])
	{
		node = create_node(envp[i]);
		if (!node || !add_node(env, node))
		{
			node_free(node);
			free_env(env);
			return (NULL);
		}
		i++;
	}
	increment_shlvl(env);
	return (env);
}

t_shell	*init_shell(char **envp)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->environ = init_env(envp);
	if (!shell->environ)
	{
		free(shell);
		return (NULL);
	}
	shell->rl_input = NULL;
	shell->rl_copy = NULL;
	shell->lex_head = NULL;
	shell->executor = NULL;
	shell->exit_status = 0;
	shell->pid_list = NULL;
	shell->saved_stdin = 0;
	shell->saved_stdout = 0;
	return (shell);
}
