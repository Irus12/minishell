/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 20:22:25 by nschilli          #+#    #+#             */
/*   Updated: 2026/08/24 20:18:28 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

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