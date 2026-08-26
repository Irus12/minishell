/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:40:27 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 16:40:39 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_list(t_env *env_list)
{
	t_env_node	*tmp;

	while (env_list->head != NULL)
	{
		tmp = env_list->head;
		env_list->head = env_list->head->next;
		free(tmp->key);
		free(tmp->val);
		free(tmp);
	}
}

void	error_command(const char *message)
{
	perror(message);
	_exit(EXIT_FAILURE);
}

void	command_not_found(char *cmd, t_shell *shell)
{
	char	*error_message;

	error_message = "Command not found: ";
	write(STDERR_FILENO, error_message, ft_strlen(error_message));
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, "\n", 1);
	shell->exit_status = 127;
	exit(127);
}
