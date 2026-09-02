/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:38:16 by romeo             #+#    #+#             */
/*   Updated: 2026/09/02 14:09:16 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pid_list	*init_pid_list(void)
{
	t_pid_list	*list;

	list = malloc(sizeof(t_pid_list));
	if (!list)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	list->pids = malloc(sizeof(pid_t) * 10);
	if (!list->pids)
	{
		perror("Error: malloc failed");
		free(list);
		exit(EXIT_FAILURE);
	}
	list->count = 0;
	list->capacity = 10;
	return (list);
}

void	add_pid(t_pid_list *list, pid_t pid)
{
	pid_t	*new_pids;

	if (list->count >= list->capacity)
	{
		list->capacity *= 2;
		new_pids = realloc(list->pids, sizeof(pid_t) * list->capacity);
		if (!new_pids)
		{
			perror("Error: realloc failed");
			free(list->pids);
			free(list);
			exit(EXIT_FAILURE);
		}
		list->pids = new_pids;
	}
	list->pids[list->count++] = pid;
}

// void	wait_all_pids(t_pid_list *list, t_exec *cmd)
// {
// 	size_t	i;
// 	int		status;

// 	(void)cmd;
// 	i = 0;
// 	while (i < list->count)
// 	{
// 		waitpid(list->pids[i], &status, WUNTRACED);
// 		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
// 			write(1, "\n", 1);
// 		i++;
// 	}
// }

void	wait_all_pids(t_pid_list *list, t_exec *cmd, t_shell *shell)
{
	size_t	i;
	int		status;

	(void)cmd;
	i = 0;
	while (i < list->count)
	{
		waitpid(list->pids[i], &status, WUNTRACED);

		if (WIFEXITED(status))
			shell->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			shell->exit_status = 128 + WTERMSIG(status);
			if (WTERMSIG(status) == SIGINT)
				write(1, "\n", 1);
			else if (WTERMSIG(status) == SIGQUIT)
				write(2, "Quit (core dumped)\n", 19);
		}
		i++;
	}
}

void	free_pid_list(t_pid_list *list)
{
	if (list)
	{
		free(list->pids);
		free(list);
	}
	list = NULL;
}
