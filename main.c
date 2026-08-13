/*
here i want to test if the whole chain works
*/

#include "minishell.h"

void    print_node(t_token_list *node)
{
	if (!node)
		return ;
	printf("--- NODE's index : %d  ---\n", node->index);
	printf("str:        %s\n", node->str ? node->str : "(null)");
	printf("type:       %d\n", node->type);
	printf("index:      %d\n", node->index);
	printf("is_command: %d\n", node->is_command);
	printf("prev:       %s\n", node->prev ? node->prev->str : "(null)");
	printf("next:       %s\n", node->next ? node->next->str : "(null)");
	printf("-------------------------\n");
}

void    print_list(t_token_list *head)
{
	while (head)
	{
		print_node(head);
		head = head->next;
	}
}

/*
on a pas free le lexer_tab quand on le transforme en token_list
ni la string original du prompte
*/

int	main(void)
{
	//char *cmd = "salut mon amis";

	t_token_list *list = parser("ls -R | grep '$?' , c'est bien");
	print_list(list);
	free_token_list(list);
}