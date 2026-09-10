/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:28:53 by romeo             #+#    #+#             */
/*   Updated: 2026/09/10 18:52:50 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
Used to make -nnnn... equivalant to -n
*/
int		correct_option(char *cmd)
{
	int	i;

	i = 2;
	if (cmd[0] == '-' && cmd[1] == 'n')
	{
		while(cmd[i])
		{
			if (cmd[i] != 'n' && cmd[i] != '\0')
			return (0);
			i++;
		}
	}
	return (1);
}

void	ft_echo(char **execs, t_shell *shell)
{
	int	flag;
	int	i;

	flag = 0;
	i = 1;
	if (execs[i] && (correct_option(execs[i]) == 1))
	{
		flag = 1;
		i++;
	}
	while (execs[i])
	{
		printf("%s", execs[i]);
		if (execs[i + 1])
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
	shell->exit_status = 0;
}
