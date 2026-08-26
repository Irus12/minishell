/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:29:02 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 16:29:07 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_env_node *env)
{
	t_env_node	*temp;

	if (!env)
		return ;
	temp = env;
	while (temp)
	{
		if (temp->key && temp->val)
			printf("%s=%s\n", temp->key, temp->val);
		temp = temp->next;
	}
}
