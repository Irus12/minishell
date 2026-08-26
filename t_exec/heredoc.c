/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:33:27 by romeo             #+#    #+#             */
/*   Updated: 2026/08/26 01:45:07 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	g_exist_status = 0;

// void	handle_hereline(int tmp_fd, char *del, int is_exp, t_shell *shell)
// {
// 	char		*line;
// 	size_t		delim_len;

// 	delim_len = ft_strlen(del);
// 	while (1)
// 	{
// 		ft_signal(4);
// 		line = readline("> ");
// 		if (!line || g_exist_status)
// 			break ;
// 		if (ft_strncmp(line, del, delim_len) == 0
// 			&& line[delim_len] == '\0')
// 		{
// 			free(line);
// 			break ;
// 		}
// 		write_line_to_fd(line, tmp_fd, is_exp, shell);
// 		free(line);
// 	}
// }

// void	handle_heredoc(char *delimiter, int should_expand, t_shell *shell)
// {
// 	int		tmp_fd;
// 	char	*tmp_filename;

// 	g_exist_status = 0;
// 	tmp_filename = "/tmp/minishell_heredoc_tmp";
// 	tmp_fd = open(tmp_filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
// 	if (tmp_fd == -1)
// 	{
// 		perror("minishell: open");
// 		shell->exit_status = 127;
// 		return ;
// 	}
// 	handle_hereline(tmp_fd, delimiter, should_expand, shell);
// 	if (g_exist_status)
// 	{
// 		shell->exit_status = 130;
// 		write(1, "Heredoc interrupted\n", 20);
// 	}
// 	close(tmp_fd);
// }

// // Main heredoc handling function
// static void	redirect_heredoc_input(t_exec *node)
// {
// 	char	*tmp_filename;
// 	int		tmp_fd;

// 	tmp_filename = "/tmp/minishell_heredoc_tmp";
// 	tmp_fd = open(tmp_filename, O_RDONLY);
// 	if (tmp_fd == -1)
// 	{
// 		perror("minishell: open");
// 		return ;
// 	}
// 	node->fd_in = tmp_fd;
// 	node->heredoc = 1;
// }

// static void	cleanup_heredoc(t_exec *node)
// {
// 	if (node->fd_in > 0)
// 	{
// 		close(node->fd_in);
// 		node->fd_in = -1;
// 	}
// 	unlink("/tmp/minishell_heredoc_tmp");
// }

// void	handle_here_redir(t_exec *node, t_token_list *current, t_shell *shell)
// {
// 	int		should_expand;
// 	char	*delimiter;

// 	while (current && current->next && current->type == HEREDOC)
// 	{
// 		current = current->next;
// 		if (!current)
// 		{
// 			write(2, "Heredoc: Missing delimiter\n", 27);
// 			return ;
// 		}
// 		should_expand = !(current->quoted);
// 		delimiter = ft_strdup(current->str);
// 		if (!delimiter)
// 			return ;
// 		cleanup_heredoc(node);
// 		handle_heredoc(delimiter, should_expand, shell);
// 		free(delimiter);
// 		if (g_exist_status)
// 			return ;
// 	}
// 	redirect_heredoc_input(node);
// }
