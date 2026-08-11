/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:56:29 by nschilli          #+#    #+#             */
/*   Updated: 2026/08/11 15:03:31 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
size_t	ft_strlcpy(char *dst, char *src, size_t dsize)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(src);
	if (dsize == 0)
		return (slen);
	i = 0;
	while (i < dsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
*/

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

/*
void    print_node(t_token_list *node)
{
    if (!node)
        return ;
    printf("--- NODE's index : %d  ---\n", node->index);
    printf("str:        %s\n", node->str ? node->str : "(null)");
    printf("type:       %d\n", node->type);
    printf("index:      %d\n", node->index);
    printf("is_command: %d\n", node->is_command);
    printf("prev:       %s\n", node->prev ? node->prev->str : "(null)");
    printf("next:       %s\n", node->next ? node->next->str : "(null)");
    printf("-------------------------\n");
}

void    print_list(t_token_list *head)
{
    while (head)
	{
		print_node(head);
		head = head->next;
    }
}

int	main()
{
	t_token_list **stack = malloc(sizeof(t_token_list *));
	*stack = NULL;
	list_append(stack, new_node("yds"));
	list_append(stack, new_node("ls"));
	list_append(stack, new_node("|"));
	list_append(stack, new_node(">"));
	list_append(stack, new_node(">>"));
	list_append(stack, new_node("<"));
	list_append(stack, new_node("<<"));

	print_list(*stack);
}

*/