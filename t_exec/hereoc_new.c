/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hereoc_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:02:30 by romeo             #+#    #+#             */
/*   Updated: 2026/09/10 17:22:10 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_hereline(int fd, char *del, int expand, t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, del) == 0)
		{
			free(line);
			break ;
		}
		write_line_to_fd(line, fd, expand, shell);
		free(line);
	}
}

static void	heredoc_child(char *del, int expand, t_shell *shell)
{
	int	fd;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	fd = open("/tmp/minishell_heredoc_tmp",
			O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		exit(1);
	handle_hereline(fd, del, expand, shell);
	close(fd);
	exit(0);
}

static int	wait_heredoc(pid_t pid, t_shell *shell)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, 0);
	ft_signal(1, shell);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		write(1, "\n", 1);
		shell->exit_status = 130;
		shell->here_stop = 1;
		unlink("/tmp/minishell_heredoc_tmp");
		return (0);
	}
	return (1);
}

static int	handle_heredoc(char *del, int expand, t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
		heredoc_child(del, expand, shell);
	return (wait_heredoc(pid, shell));
}

void	handle_here_redir(t_exec *node, t_token_list *current, t_shell *shell)
{
	char	*delimiter;
	int		expand;

	if (!current || !current->next)
		return ;
	current = current->next;
	expand = !current->is_quoted;
	delimiter = ft_strdup(current->str);
	if (!delimiter)
		return ;
	cleanup_heredoc(node);
	if (!handle_heredoc(delimiter, expand, shell))
	{
		free(delimiter);
		return ;
	}
	free(delimiter);
	redirect_heredoc_input(node);
}
