/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_new_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 18:07:27 by romeo             #+#    #+#             */
/*   Updated: 2026/09/09 18:23:02 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	write_expanded_line(char *line, int fd, t_shell *shell)
{
	char	*expanded;

	expanded = heredoc_expander(line, shell);
	if (!expanded)
	{
		write(fd, line, ft_strlen(line));
		return ;
	}
	write(fd, expanded, ft_strlen(expanded));
	free(expanded);
}

void	write_line_to_fd(char *line, int fd, int expand, t_shell *shell)
{
	if (expand)
		write_expanded_line(line, fd, shell);
	else
		write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
}

void	cleanup_heredoc(t_exec *node)
{
	if (node->fd_in > 0)
	{
		close(node->fd_in);
		node->fd_in = -1;
	}
	unlink("/tmp/minishell_heredoc_tmp");
}

void	redirect_heredoc_input(t_exec *node)
{
	int	fd;

	fd = open("/tmp/minishell_heredoc_tmp", O_RDONLY);
	if (fd == -1)
	{
		perror("minishell: heredoc");
		return ;
	}
	node->fd_in = fd;
	node->heredoc = 1;
	unlink("/tmp/minishell_heredoc_tmp");
}
