/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:45:47 by romeo             #+#    #+#             */
/*   Updated: 2026/08/26 01:45:56 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	link_exec_with_pipe(t_exec *node_exec, t_exec_context *context)
{
	int	pipe_fds[2];

	if (pipe(pipe_fds) == -1)
	{
		perror("pipe");
		return ;
	}
	if (node_exec->fd_out == 1)
		node_exec->fd_out = pipe_fds[1];
	node_exec->pipe_out = pipe_fds[1];
	context->fd_pipe = pipe_fds[0];
	node_exec->piped = 1;
}
