/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exec_creation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:12:07 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 17:27:33 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	assign_command(t_shell *shell, t_exec_context *c)
{
	(void)shell;
	if (!c->current_exec)
		return ;
	c->current_exec->execs = tab_command(c);
	while (c->current_lexer && c->current_lexer->type == WORD)
		c->current_lexer = c->current_lexer->next;
}

void	update_exec_links(t_exec_context *context, t_exec *new_exec_node)
{
	if (!context || !new_exec_node)
		return ;
	if (!context->exec_head)
		context->exec_head = new_exec_node;
	else
		context->current_exec->next = new_exec_node;
	context->current_exec = new_exec_node;
	if (context->exec_id > 1 && context->current_lexer
		&& context->current_lexer->prev
		&& context->current_lexer->prev->type == PIPE)
		context->current_exec->pipe_in = context->fd_pipe;
}

int	process_lexer_node(t_shell *shell, t_exec_context *context)
{
	while (context->current_lexer && context->current_lexer->type != WORD)
	{
		if (context->current_lexer->type == TRUNCATE
			|| context->current_lexer->type == REDIRECT_INPUT
			|| context->current_lexer->type == APPEND
			|| context->current_lexer->type == HEREDOC)
		{
			if (!context->current_lexer->next
				|| context->current_lexer->next->type != WORD)
			{
				write(STDERR_FILENO, "minishell: syntax error\n", 24);
				return (0);
			}
		}
		handle_redirection(shell, context);
	}
	if (context->current_lexer && context->current_lexer->type == WORD)
		assign_command(shell, context);
	while (context->current_lexer && context->current_lexer->type != WORD)
		handle_redirection(shell, context);
	return (1);
}
