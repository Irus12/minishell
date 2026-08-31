/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:56:29 by nschilli          #+#    #+#             */
/*   Updated: 2026/08/24 20:16:15 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//put ft_strlen instead of 2 and 1
t_token assign_token_type(char *str)
{
	if (ft_strncmp(str, "<<", 2) == 0)
		return(HEREDOC); 
	else if (ft_strncmp(str, "<", 1) == 0)
		return (REDIRECT_INPUT);
	else if (ft_strncmp(str, ">>", 2) == 0)
		return (APPEND);
	else if (ft_strncmp(str, ">", 1) == 0)
		return (TRUNCATE);
	else if (ft_strncmp(str, "|", 2) == 0)
		return (PIPE);
	else
		return (WORD);
}

/*
Create a new token node with every parameter set as NULL except it's string
*/
t_token_list	*new_node(char *word)
{
	t_token_list	*new;

	new = malloc(sizeof(t_token_list));
	if (!new)
		return (NULL);
	
	new->str = malloc((ft_strlen(word) + 1 ) * sizeof(char));
	if (!new->str)
		return (free(new), NULL);
	ft_strlcpy(new->str, word, ft_strlen(word) + 1);
	new->type = assign_token_type(word);
	new->index = 0;
	new->is_command = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/*
Will append a node at the end of t_token_list
*/
void	list_append(t_token_list **head, t_token_list *new)
{
	t_token_list	*tmp;

	if (!head || !new)
		return ;
	if (!*head)
	{
		new->is_command = 1;
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	new->index = tmp->index + 1;
	if (tmp->type == PIPE)
		new->is_command = 1;
}

void	list_init(t_token_list **stack, char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		list_append(stack, new_node(arr[i]));
		i++;
	}
}

t_token_list	new_token_list()
{
	t_token_list out;
	out.str = NULL;
	out.prev = NULL;
	out.next = NULL;
	return (out);
}

void	free_token_list(t_token_list *head)
{
	t_token_list	*tmp;

	while(head)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}
