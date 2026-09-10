#include "../minishell.h"

void    print_node(t_token_list *node)
{
	if (!node)
		return ;
	while(node)
	{
	printf("--- NODE's index : %d  ---\n", node->index);
	printf("str:        %s\n", node->str ? node->str : "(null)");
	printf("type:       %d\n", node->type);
	printf("index:      %d\n", node->index);
	printf("is_command: %d\n", node->is_command);
	printf("prev:       %s\n", node->prev ? node->prev->str : "(null)");
	printf("next:       %s\n", node->next ? node->next->str : "(null)");
	printf("IS_QUOTED	%d\n", node->is_quoted);
	printf("-------------------------\n");
	node = node->next;
	}
}


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
	//print_node(tokens); DEBUG
	return (tokens);
}

/*
j'ai commenter le main de minishell.c et changer des trucs du expand_str pour que ca marche
*/
/*
int main(void)
{
	t_token_list *list = parser("/|/||| /|EW < Junb <>>ou <  dwa >> y | & dw 12 !! $$USER", NULL);
	print_node(list);
	free_token_list(list);
}
*/

