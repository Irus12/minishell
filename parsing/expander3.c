/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 17:57:37 by nschilli          #+#    #+#             */
/*   Updated: 2026/09/28 12:08:15 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void append_sublist(t_token_list **list, t_token_list *to_insert)
{
	t_token_list	*last;

	if (!*list)  // liste vide après remove_node
	{
		*list = to_insert;
		return ;
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = to_insert;
	to_insert->prev = last;
}

void	redo_index(t_token_list *head)
{
	int	index;

	index = 0;
	while (head)
	{
		head->index = index++;
		head = head->next;
	}
}

/*
	will insert a sublist in between other elements of a list
	"list[insert_index] will have the first element of to_insert"

	list :		[echo]0 -> [sublist_to_add_here] -> [foo]1
	sublist :	[ls]0 -> [-R]1
	list_insert(list, sublist, 1) : [echo]0 -> [ls]1 -> [-R]2 -> [foo]3
*/

void	list_insert(t_token_list **list, t_token_list *to_insert, int insert_i)
{
	t_token_list	*node;
	t_token_list	*sub_last;

	node = *list;
	sub_last = to_insert;
	while (node && node->index < insert_i)
		node = node->next;
	if (!node)
	{
		append_sublist(list, to_insert);
		//*list = to_insert; // la sous-liste devient la liste
		redo_index(*list);
		return ;
	}
	while(sub_last->next)
		sub_last = sub_last->next;
	to_insert->prev = node->prev;
	if (node->prev)
		node->prev->next = to_insert;
	else
		*list = to_insert;
	sub_last->next = node;
	node->prev = sub_last;
	redo_index(*list);
}

/*
void    list_insert(t_token_list **list, t_token_list *to_insert, int insert_i)
{
	t_token_list    *head;
	t_token_list    *node;
	t_token_list    *sub_last;
	int             index;

	head = *list;
	node = *list;
	sub_last = to_insert;
	index = 0;
	while (node && node->index < insert_i)
		node = node->next;
	while (sub_last->next)
		sub_last = sub_last->next;
	if (!node)  // insert à la fin
	{
		t_token_list *last = *list;
		while (last->next)
			last = last->next;
		last->next = to_insert;
		to_insert->prev = last;
	}
	else
	{
		to_insert->prev = node->prev;
		if (node->prev)
			node->prev->next = to_insert;
		else
			*list = to_insert;
		sub_last->next = node;
		node->prev = sub_last;
	}
	while (head)
	{
		head->index = index++;
		head = head->next;
	}
}
	*/

void	expander_retokenize(t_token_list **main, char *str, int insert_index, int is_cmd)
{
	t_token_list	*to_insert;
	t_token_list	*node;
	char			**lexlings;
	int				size;

	remove_node(main, insert_index);
	lexlings = lexer_tab(str);
	//lexlings = ft_split(str, ' ');
	size = 0;
	while (lexlings[size])
		size++;
	to_insert = NULL;
	list_init(&to_insert, lexlings, size);
	//print_node(to_insert);
	to_insert->is_command = is_cmd;
	node = to_insert;
	//iterer dans to_insert et mettre is_command = 0
		while(node) 
		{
			node->type = WORD;
			node->is_command = 0;
			node = node->next;
		}
	list_insert(main, to_insert, insert_index);
}
