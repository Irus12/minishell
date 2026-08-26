/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:28:15 by romeo             #+#    #+#             */
/*   Updated: 2026/08/25 17:29:47 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_result(char **result, int count)
{
	while (--count >= 0)
		free(result[count]);
	free(result);
}

static int	is_valid_command_token(t_token_list *lexer)
{
	return (lexer->type == WORD
		|| (lexer->type != PIPE && lexer->type != REDIRECT_INPUT
			&& lexer->type != TRUNCATE && lexer->type != APPEND
			&& lexer->type != HEREDOC));
}

static int	count_commands(t_token_list *lexer)
{
	int	count;

	count = 0;
	while (lexer && (lexer->type == WORD
			|| (lexer->type != PIPE && lexer->type != REDIRECT_INPUT
				&& lexer->type != TRUNCATE && lexer->type != APPEND
				&& lexer->type != HEREDOC)))
	{
		if (lexer->type == WORD)
			count++;
		lexer = lexer->next;
	}
	return (count);
}

char	**tab_command(t_exec_context *context)
{
	t_token_list	*lexer;
	int				cmd_count;
	char			**result;

	cmd_count = 0;
	lexer = context->current_lexer;
	result = malloc(sizeof(char *) * (count_commands(lexer) + 1));
	if (!result)
		return (NULL);
	while (lexer && is_valid_command_token(lexer))
	{
		if (lexer->type == WORD)
		{
			result[cmd_count] = ft_strdup(lexer->str);
			if (!result[cmd_count])
			{
				free_result(result, cmd_count);
				return (NULL);
			}
			cmd_count++;
		}
		lexer = lexer->next;
	}
	result[cmd_count] = NULL;
	return (result);
}
