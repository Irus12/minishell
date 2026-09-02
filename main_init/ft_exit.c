/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:05:38 by romeo             #+#    #+#             */
/*   Updated: 2026/08/31 18:47:22 by romeo            ###   ########.fr       */
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
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
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
		printf("exit: too many arguments\n");
		return ;
	}
	if (args && args[1] && !is_numeric(args[1]))
	{
		printf("exit: %s: numeric argument required\n", args[1]);
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
