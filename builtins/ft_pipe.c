/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:29:15 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 16:29:16 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

pid_t	handle_forks(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		return (-1);
	}
	return (pid);
}

int	handle_pipes(int fildes[2])
{
	if (pipe(fildes) == -1)
	{
		perror("pipe failed");
		return (-1);
	}
	return (0);
}

void	safe_pid(pid_t pid)
{
	if (pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
}
