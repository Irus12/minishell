/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:35:05 by kbaga             #+#    #+#             */
/*   Updated: 2026/08/20 18:06:12 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_arr(char **arr, int size)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < size)
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	free(arr);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_exec(t_exec *list)
{
	t_exec	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		if (temp->path)
			free_tab(temp->path);
		if (temp->execs)
			free_tab(temp->execs);
		free(temp);
	}
	list = NULL;
}

void	free_heap(t_shell *shell)
{
	if (shell->rl_input)
		free(shell->rl_input);
	if (shell->rl_copy)
		free(shell->rl_copy);
	if (shell->environ)
		free_env(shell->environ);
	if (shell->lex_head)
		free_lex(shell->lex_head);
	if (shell->executor)
		free_exec(shell->executor);
}

t_token_ctx	*free_lex(t_token_list *lex_head)
{
	t_token_list	*curr;
	t_token_list	*next_node;

	if (!lex_head)
		return (NULL);
	curr = lex_head;
	while (curr != NULL)
	{
		next_node = curr->next;
		if (curr->str)
			free(curr->str);
		free(curr);
		curr = next_node;
	}
	return (lex_head);
}
