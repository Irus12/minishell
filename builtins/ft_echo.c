/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:28:53 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 16:35:32 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **execs, t_shell *shell)
{
	int	flag;
	int	i;

	flag = 0;
	i = 1;
	if (execs[i] && ft_strcmp(execs[i], "-n") == 0)
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
