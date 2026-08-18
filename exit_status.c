/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 20:22:25 by nschilli          #+#    #+#             */
/*   Updated: 2026/08/13 22:55:13 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

/*
imitate a global variable that stores the last exit status
askip à appeller après chaque waitpid() comme ca :
*get_status() = WEXITSTATUS(status);
*/
int	*get_status()
{
	static int	n;

	return (&n);
}