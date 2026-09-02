#include "../minishell.h"

void	free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_token_list *parser(char *str, t_shell *shell)
{
	char			**lexlings;
	t_token_list	*tokens;
	int	size;

	tokens = NULL;
	size = 0;
	lexlings = lexer_tab(str);
	while(lexlings[size])
		size++;
	list_init(&tokens, lexlings, size);
	list_expander(&tokens, shell);
	free_double_tab(lexlings);
	list_quote_cleaner(tokens); //va plus loin dans la chaine des événements ?
	return (tokens);
}
