/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:28:36 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 16:28:42 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_env_var(t_env_node *env, const char *key)
{
	while (env)
	{
		if (strcmp(env->key, key) == 0)
			return (env->val);
		env = env->next;
	}
	return (NULL);
}

static void	update_env_var(t_env_node *env, char *key, char *value)
{
	t_env_node	*curr;
	t_env_node	*new_node;

	curr = env;
	while (curr)
	{
		if (strcmp(curr->key, key) == 0)
		{
			free(curr->val);
			curr->val = ft_strdup(value);
			return ;
		}
		curr = curr->next;
	}
	new_node = malloc(sizeof(t_env_node));
	if (!new_node)
		return ;
	new_node->key = ft_strdup(key);
	new_node->val = ft_strdup(value);
	new_node->next = env->next;
	env->next = new_node;
}

void	handle_cd_dash(t_env *env)
{
	char	*oldpwd;
	char	*current_pwd;

	oldpwd = get_env_var(env->head, "OLDPWD");
	if (!oldpwd)
	{
		write(STDERR_FILENO, "cd: OLDPWD not set\n", 20);
		return ;
	}
	current_pwd = getcwd(NULL, 0);
	if (!current_pwd || chdir(oldpwd) == -1)
	{
		perror("cd");
		free(current_pwd);
		return ;
	}
	printf("%s\n", oldpwd);
	update_env_var(env->head, "OLDPWD", current_pwd);
	free(current_pwd);
	current_pwd = getcwd(NULL, 0);
	if (current_pwd)
	{
		update_env_var(env->head, "PWD", current_pwd);
		free(current_pwd);
	}
}

void	ft_cd(t_env *env, char **args)
{
	char	*current_pwd;
	char	*new_pwd;

	if (!args[1] || args[2])
	{
		write(STDERR_FILENO, "cd: wrong syntax\n", 18);
		return ;
	}
	current_pwd = getcwd(NULL, 0);
	if (ft_strcmp(args[1], "-") == 0)
	{
		handle_cd_dash(env);
		return ;
	}
	if (!current_pwd || chdir(args[1]) == -1)
	{
		perror("cd");
		free(current_pwd);
		return ;
	}
	new_pwd = getcwd(NULL, 0);
	update_env_var(env->head, "OLDPWD", current_pwd);
	update_env_var(env->head, "PWD", new_pwd);
	free(current_pwd);
	free(new_pwd);
}
