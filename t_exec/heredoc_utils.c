/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 18:22:26 by romeo             #+#    #+#             */
/*   Updated: 2026/09/09 18:22:33 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../minishell.h"

// static void	write_expanded_line(char *line, int fd, t_shell *shell)
// {
// 	char	*expanded;

// 	expanded = heredoc_expander(line, shell);
// 	if (!expanded)
// 	{
// 		write(fd, line, ft_strlen(line));
// 		return ;
// 	}
// 	write(fd, expanded, ft_strlen(expanded));
// 	free(expanded);
// }

// void	write_line_to_fd(char *line, int fd, int should_expand, t_shell *shell)
// {
// 	if (should_expand)
// 		write_expanded_line(line, fd, shell);
// 	else
// 		write(fd, line, ft_strlen(line));
// 	write(fd, "\n", 1);
// }/ 