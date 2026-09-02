/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:32:00 by romeo             #+#    #+#             */
/*   Updated: 2026/09/02 14:21:03 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Handling > (Truncate) Redirection
void	handle_truncate_redirection(t_exec *node, t_token_list *current)
{
	int	fd;

	current = current->next;
	fd = open(current->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		g_exit_status = 127;
		return ;
	}
	node->fd_out = fd;
	node->trunc = 1;
}

void	handle_append_redirection(t_exec *node, t_token_list *current)
{
	int	fd;

	current = current->next;
	fd = open(current->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror("open");
		return ;
	}
	node->fd_out = fd;
	node->append = 1;
}

void	handle_input_redirection(t_exec *node, t_token_list *current)
{
	int		fd;
	char	*filename;

	current = current->next;
	fd = open(current->str, O_RDONLY);
	if (fd == -1)
	{
		filename = current->str;
		perror(filename);
		g_exit_status = 1;
		if (node->fd_in == STDIN_FILENO)
			node->fd_in = -1;
		return ;
	}
	if (node->fd_in != STDIN_FILENO && node->fd_in != -1)
	{
		close(node->fd_in);
		node->fd_in = -1;
	}
	node->fd_in = fd;
	node->redir_input = 1;
}

void	handle_redirection(t_shell *shell, t_exec_context *c)
{
	(void)shell;
	if (!c || !c->current_lexer->next || !c->current_lexer)
		return ;
	if (c->current_lexer->type == TRUNCATE)
		handle_truncate_redirection(c->current_exec, c->current_lexer);
	else if (c->current_lexer->type == APPEND)
		handle_append_redirection(c->current_exec, c->current_lexer);
	else if (c->current_lexer->type == REDIRECT_INPUT)
		handle_input_redirection(c->current_exec, c->current_lexer);
	else if (c->current_lexer->type == HEREDOC)
		printf("caca\n");
		//handle_here_redir(c->current_exec, c->current_lexer, shell); ////a corriger les heredocs
	else if (c->current_lexer->type == PIPE)
	{
		link_exec_with_pipe(c->current_exec, c);
		c->current_lexer = c->current_lexer->next;
		return ;
	}
	if (c->current_lexer && c->current_lexer->next)
		c->current_lexer = c->current_lexer->next->next;
	else
		c->current_lexer = NULL;
}
