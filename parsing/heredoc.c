/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:29:21 by nschilli          #+#    #+#             */
/*   Updated: 2026/08/31 17:44:41 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
est-ce que les heredocs conservent les paires de quotes ? besoin de fonction cleanup_pairs_of_quotes ?

void	*heredoc_expander(char *line)
{
	t_expand_state	state;
	char	in_quote;
	int		i;

	state.new_str = ft_strdup("");
	state.og_str = line;
	in_quote = 0;
	i = 0;
	while (line[i])
	{
		if (in_quote == 0 && state.og_str[i] == '\'' && quote_can_be_closed(state.og_str, '\'')) // si simple on skip le getenv
			assign_skip(&in_quote, '\'', &i, &state);
		else if (in_quote == '\'' && state.og_str[i] == '\'')
			assign_skip(&in_quote, 0, &i, &state);
		else if (state.og_str[i] == '$' && in_quote == 0)
			expand_str(&state.og_str, &state.new_str, &i);
		else
			str_append_char(&state.new_str, state.og_str[i++]);
	}
	return (state.new_str);
}
	*/