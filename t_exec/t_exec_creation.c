/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exec_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:43:39 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 14:43:50 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exec	*handle_exec_creation(t_shell *shell, t_exec_context *context)
{
	t_exec	*new_exec_node;

	new_exec_node = create_exec_node(context->exec_id++);
	if (!new_exec_node)
	{
		free_exec(context->exec_head);
		free(context);
		return (NULL);
	}
	update_exec_links(context, new_exec_node);
	if (!process_lexer_node(shell, context))
	{
		free_exec_node(new_exec_node);
		free_exec(context->exec_head);
		free(context);
		return (NULL);
	}
	return (new_exec_node);
}

int	check_pipe_validity(t_exec_context *context)
{
	if (!context || !context->current_lexer)
		return (1);
	if (context->current_lexer->type == PIPE)
	{
		if (!context->current_lexer->next)
		{
			write(2, "minishell: syntax error near unexpected token `|'\n", 48);
			return (0);
		}
	}
	return (1);
}

t_exec	*create_exec_list(t_shell *shell)
{
	t_exec_context	*context;
	t_exec			*result_head;

	context = malloc(sizeof(t_exec_context));
	if (!context)
		return (NULL);
	init_exec_context(context, shell);
	if (!check_pipe_validity(context))
	{
		free(context);
		return (NULL);
	}
	while (context->current_lexer)
	{
		if (!handle_exec_creation(shell, context))
			return (NULL);
	}
	result_head = context->exec_head;
	free(context);
	return (result_head);
}
