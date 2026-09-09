/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:33:27 by romeo             #+#    #+#             */
/*   Updated: 2026/09/09 18:16:59 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minishell.h"

// // int	g_exist_status = 0;
// void	handle_hereline(int tmp_fd, char *del, int is_exp, t_shell *shell)
// {
// 	char		*line;
// 	size_t		delim_len;

// 	delim_len = ft_strlen(del);
// 	ft_signal(4, shell);
// 	while (1)
// 	{
// 		line = readline("> ");
// 		if (g_exit_status == 130)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		if (!line)
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
// 	ft_signal(1, shell);
// }

// void	handle_heredoc(char *delimiter, int should_expand, t_shell *shell)
// {
// 	int		tmp_fd;
// 	char	*tmp_filename;

// 	shell->exit_status = 0;
// 	tmp_filename = "/tmp/minishell_heredoc_tmp";
// 	tmp_fd = open(tmp_filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
// 	if (tmp_fd == -1)
// 	{
// 		perror("minishell: open");
// 		shell->exit_status = 127;
// 		return ;
// 	}
// 	handle_hereline(tmp_fd, delimiter, should_expand, shell);
// 	if (shell->exit_status)
// 	{
// 		shell->exit_status = 130;
// 		write(1, "Heredoc interrupted\n", 20);
// 	}
// 	close(tmp_fd);
// }

// // Main heredoc handling function
// static void	redirect_heredoc_input(t_exec *node)
// {
// 	int	tmp_fd;

// 	tmp_fd = open("/tmp/minishell_heredoc_tmp", O_RDONLY);
// 	if (tmp_fd == -1)
// 	{
// 		perror("minishell: open");
// 		return ;
// 	}
// 	node->fd_in = tmp_fd;
// 	node->heredoc = 1;
// 	unlink("/tmp/minishell_heredoc_tmp");
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

// 	if (!current || !current->next)
// 		return ;
// 	current = current->next;
// 	should_expand = !current->is_quoted;
// 	delimiter = ft_strdup(current->str);
// 	if (!delimiter)
// 		return ;
// 	cleanup_heredoc(node);
// 	g_exit_status = 0;
// 	handle_heredoc(delimiter, should_expand, shell);
// 	free(delimiter);
// 	if (g_exit_status == 130)
// 	{
// 		shell->exit_status = 130;
// 		unlink("/tmp/minishell_heredoc_tmp");
// 		return ;
// 	}
// 	redirect_heredoc_input(node);
// }
