/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:05:38 by romeo             #+#    #+#             */
/*   Updated: 2026/09/28 15:57:31 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_shell *shell, char **args)
{
	int	exit_code;

	if (args && args[1] && args[2])
	{
		shell->exit_status = 1;
		write(2, "exit: too many arguments\n", 26);
		return ;
	}
	if (args && args[1] && !is_numeric(args[1]))
	{
		write(2, "exit\n", 5);
		write(2, "exit: ", 7);
		write(2, args[1], ft_strlen(args[1]));
		write(2, ": numeric argument required\n", 28);
		exit_code = 2;
	}
	else if (args && args[1])
		exit_code = atoi(args[1]);
	else
		exit_code = shell->exit_status;
	free_exec_list(shell->executor);
	free_env(shell->environ);
	free_lex(shell->lex_head);
	exit(exit_code);
}
