/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 18:23:35 by romeo             #+#    #+#             */
/*   Updated: 2026/09/09 18:23:43 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	old_prompt(int sig)
{
	g_exit_status = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

static void	old_prompt_2(int sig)
{
	g_exit_status = 1;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	(void)sig;
}

static void	ctrl_c(int sig)
{
	write(1, "\n", 1);
	exit(0);
	(void)sig;
}

void	ft_signal(int sig, t_shell *shell)
{
	(void)shell;
	if (sig == 1)
	{
		signal(SIGINT, old_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (sig == 2)
	{
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (sig == 3)
		exit(0);
	else if (sig == 5)
	{
		signal(SIGINT, old_prompt_2);
		signal(SIGQUIT, SIG_IGN);
	}
}
