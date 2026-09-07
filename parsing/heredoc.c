/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:29:21 by nschilli          #+#    #+#             */
/*   Updated: 2026/09/07 15:04:37 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
est-ce que les heredocs conservent les paires de quotes ? besoin de fonction cleanup_pairs_of_quotes ?
*/
/*
check if a pair of single quote is quoting the whole word
remplacable par quote_can_be_closed(char *str, char quote) ?
*/
int	is_heredoc_expandable(char *delimiter)
{
	if (str_has_closing_quotes(delimiter))
		return 0;
	return 1;
}
/*
char	*heredoc_expander(char *line, t_shell *shell)
{
	t_expand_state	state;
	int				i;

	state.new_str = ft_strdup("");
	state.og_str = line;

	i = 0;
	while (line[i])
	{
		if (state.og_str[i] == '$')
			expand_str(&state.og_str, &state.new_str, &i, shell);
		else
			str_append_char(&state.new_str, state.og_str[i++]);
	}
	return (state.new_str);
}
*/
