/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:44:43 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 14:45:06 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	old_prompt(int sig)
{
	g_exit_status = 1;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

static void	old_prompt_2(int sig)
{
	g_exit_status = 1;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	(void)sig;
}

static void	heredoc(int sig)
{
	g_exit_status = 1;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	(void)sig;
}

static void	ctrl_c(int sig)
{
	printf("\n");
	exit(0);
	(void)sig;
}

void	ft_signal(int sig)
{
	if (sig == 1)
	{
		signal(SIGINT, old_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 2)
	{
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 3)
		exit(0);
	if (sig == 4)
	{
		signal(SIGINT, heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 5)
	{
		signal(SIGINT, old_prompt_2);
		signal(SIGQUIT, SIG_IGN);
	}
}
