/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:08:43 by romeo             #+#    #+#             */
/*   Updated: 2026/09/10 18:41:58 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	node_free(t_env_node *node)
{
	free(node->key);
	free(node->val);
	free(node);
}

int	export_args(t_shell *shell, char **args)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (args[i] != NULL)
	{
		if (!is_valid_id(args[i]))
			error = 1;
		else if (!create_add(shell, args[i]))
			return (0);
		i++;
	}
	shell->exit_status = error;
	return (1);
}

int	export(t_shell *shell, char **args)
{
	shell->exit_status = 0;
	if (!args || !*args)
	{
		if (!exp_no_args(shell->environ))
		{
			shell->exit_status = 1;
			return (0);
		}
		return (1);
	}
	if (!export_args(shell, args))
	{
		shell->exit_status = 1;
		return (0);
	}
	return (1);
}

void	exporting(t_shell *shell, char *str)
{
	t_env_node	*node;
	int			pos;
	char		*key;

	if (!shell || !str)
	{
		export(shell, NULL);
		return ;
	}
	pos = 0;
	key = ext_key(str, &pos);
	if (!key)
		return ;
	node = get_node(shell->environ, key);
	if (node)
	{
		existing_node(node, str, pos);
		free(key);
		return ;
	}
	new_node2(shell->environ, key, str, pos);
}
