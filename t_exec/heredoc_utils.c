/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 14:26:59 by romeo             #+#    #+#             */
/*   Updated: 2026/09/02 14:29:55 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	write_expanded_line(char *line, int tmp_fd, t_shell *shell)
// {
// 	char	*expanded;

// 	expanded = interpolate(shell, line);
// 	if (expanded)
// 	{
// 		write(tmp_fd, expanded, ft_strlen(expanded));
// 		free(expanded);
// 	}
// 	else
// 		write(tmp_fd, line, ft_strlen(line));
// }

void	write_line_to_fd(char *l, int fd, int exp, t_shell *shell)
{
	(void)shell;
	if (exp)
		// write_expanded_line(l, fd, shell);
		printf("caca, pas expand implemented\n");
	else
		write(fd, l, ft_strlen(l));
	write(fd, "\n", 1);
}
