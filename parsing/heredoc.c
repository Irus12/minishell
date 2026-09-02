/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:29:21 by nschilli          #+#    #+#             */
/*   Updated: 2026/09/02 16:27:56 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	quote_can_be_closed(char *str, char quote)
{
	int		i;
	char	in_quote;

	i = 0;
	in_quote = 0;
	while (str[i])
	{
		if (!in_quote && (str[i] == quote))
			in_quote = str[i++];
		if (in_quote && (str[i] == in_quote))
		{
			in_quote = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

/*
est-ce que les heredocs conservent les paires de quotes ? besoin de fonction cleanup_pairs_of_quotes ?
*/
/*
check if a pair of single quote is quoting the whole word
remplacable par quote_can_be_closed(char *str, char quote) ?
*/
int	is_heredoc_expandable(char *delimiter)
{
	/*
	char	in_quote;
	int		i;
	int		last_i;
	int		pairs_of_qts;

	i = 1;
	last_i = ft_strlen(delimiter) - 1;
	if (delimiter[0] == '\'' && delimiter[last_i] == '\'')
	{
		while (i < last_i)
		{
			if (delimiter[i] == '\'')
				return (0);
		}
	}
	*/
	if (quote_can_be_closed(delimiter, '\''));
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
int	main()
{
	int n = is_heredoc_expandable("\'eof\'");
	printf("%d\n",n);
}
