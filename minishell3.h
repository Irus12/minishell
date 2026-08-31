#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef enum s_token
{
	WORD,           // word / argument de commande
	PIPE,           // |
	TRUNCATE,       // > redirige stdout vers un fichier (écrase)
	APPEND,         // >> redirige stdout vers un fichier (ajoute à la fin)
	REDIRECT_INPUT, // < redirige stdin depuis un fichier
	HEREDOC,        // << lit stdin jusqu'à un délimiteur (ex: << EOF)
}	t_token;

/*
is_command = 1 si le token précédent est NULL ou PIPE 
is_command = 0 dans tous les autres cas
cat << EOF | sort > result.txt - ici 'cat' et 'sort' is_command == 1
*/
typedef struct s_token_list
{
	char				*str;
	t_token				type;
	int					index;
	int					is_command;
	struct s_token_list	*prev;
	struct s_token_list	*next;
}	t_token_list;

/*
Struct used in the expanding process to minimize space
*/
typedef struct s_expand_state
{
	char	*og_str;
	char	*new_str;
}	t_expand_state;


/*########## TOKENS ##########*/
/* lexing */
void	clean_quotes(char **str);
int		quote_can_be_closed(char *str, char quote);
int		str_has_closing_quotes(char *str);
int		word_len(char *str);
char	*word_extractor(char *str, int size);
void	clean_quotes_word(char *word);
char	**lexer_tab(char *str);

/* expander */
char	*string_expander(char *str);
void	list_expander(t_token_list **str);

/* expander utils */
void	str_append(char **str, char *to_add);
void	str_append_char(char **str, char c);
int	has_eof_delimiter(t_token_list *tkn);

/* token list */
t_token_list	new_token_list();
void	list_init(t_token_list **stack, char **arr, int size);
void	free_token_list(t_token_list *head);

/* parsing */
t_token_list *parser(char *str);

/* utils */
int	*get_status();

#endif
