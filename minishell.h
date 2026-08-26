#ifndef MINISHELL_H
# define MINISHELL_H

/*-------- SYSTEM HEADERS --------*/
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sysexits.h>
# include <unistd.h>
# include <limits.h>
# include "libft_merged/include/libft.h"

/*---------- MACROS --------------------------*/
# define PROMPT "minishell >"
# define ERR_SYN_PIPE "Syntax error: pipes\n"
# define FAIL_SYSCALL -1
# define OKAY 0
# define FAIL_SYSCALL_PARENT 1
# define FAIL_SYSCALL_CHILD 2

/*-------- GLOBAL VARIABLES ------------------*/
extern int	g_exit_status;

typedef enum s_token
{
	WORD,           // word / argument de commande
	PIPE,           // |
	TRUNCATE,       // > redirige stdout vers un fichier (écrase)
	APPEND,         // >> redirige stdout vers un fichier (ajoute à la fin)
	REDIRECT_INPUT, // < redirige stdin depuis un fichier
	HEREDOC,        // << lit stdin jusqu'à un délimiteur (ex: << EOF)
}	t_token;

/*gestion pid*/
typedef struct s_pid_list
{
	pid_t	*pids;
	size_t	count;
	size_t	capacity;
}	t_pid_list;

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

/* Environment List */
typedef struct s_env_node
{
	char				*key;
	char				*val;
	struct s_env_node	*next;
}	t_env_node;

typedef struct s_env_list
{
	t_env_node	*head;
}	t_env;

//EXEC
typedef struct s_exec
{
	int				id;
	int				size;
	int				fd_in;
	int				fd_out;
	int				trunc;
	int				append;
	int				redir_input;
	int				heredoc;
	char			**path;
	char			**execs;
	struct s_exec	*prev;
	struct s_exec	*next;
	int				pipe_in;
	int				pipe_out;
	int				piped;
}	t_exec;

typedef struct s_exec_context
{
	t_token_list	*current_lexer;
	t_exec			*exec_head;
	t_exec			*current_exec;
	t_token_list	*lex_head;
	t_exec			*exec_tail;
	int				lex_id;
	int				exec_id;
	int				fd_pipe;
}	t_exec_context;

/* Exec Context */

typedef struct s_fd_backup
{
	int	saved_stdin;
	int	saved_stdout;
}	t_fd_backup;

/* Key-Value Pair */
typedef struct s_pair
{
	char	*key;
	char	*val;
}	t_pair;

/* Token Context */
typedef struct s_token_ctx
{
	char	**arr;
	char	*s;
	int		arr_size;
	int		index;
}	t_token_ctx;

/* Shell State */
typedef struct s_shell
{
	char				*rl_input;
	char				*rl_copy;
	int					exit_status;
	t_env				*environ;
	t_token_list		*lex_head;
	t_exec_context		*context;
	struct s_exec		*executor;
	t_pid_list			*pid_list;
	int					saved_stdin;
	int					saved_stdout;
}	t_shell;

/* Environment and shell*/
t_shell			*init_shell(char **envp);
t_env_node		*get_node(t_env *env, char *key);
t_env_node		*create_node(char *var);
t_env_node		*add_node(t_env *env, t_env_node *node);
char			*my_getenv(char *name, t_env *env_list);
void			free_env(t_env *env);
void			free_env_list(t_env *env_list);

void			node_free(t_env_node *node);

// int	*get_status();
// /*########## TOKENS ##########*/
// /* lexing */
// void			clean_quotes(char **str);
// int				quote_can_be_closed(char *str, char quote);
// int				str_has_closing_quotes(char *str);
// int				word_len(char *str);
// char			*word_extractor(char *str, int size);
// void			clean_quotes_word(char *word);

// // /* expander */
// // char	*expanding(char *str); //
// // char	*expand(char *str);

// /* expander utils */
// void			str_append(char **str, char *to_add);
// void			str_append_char(char **str, char c);
// int				has_eof_delimiter(t_token_list *tkn);

/*########## TOKENS ##########*/
/* lexing */
void			clean_quotes(char **str);
int				quote_can_be_closed(char *str, char quote);
int				str_has_closing_quotes(char *str);
int				word_len(char *str);
char			*word_extractor(char *str, int size);
void			clean_quotes_word(char *word);
char			**lexer_tab(char *str);

/* expander */
char			*string_expander(char *str);
void			list_expander(t_token_list **str);

/* expander utils */
void			str_append(char **str, char *to_add);
void			str_append_char(char **str, char c);
int				has_eof_delimiter(t_token_list *tkn);

/* token list */
t_token_list	new_token_list();
void			list_init(t_token_list **stack, char **arr, int size);
void			free_token_list(t_token_list *head);

/* parsing */
t_token_list *parser(char *str);

/* utils */
int	*get_status();

/*-----------------FD--------------*/
void			restore_fds(t_fd_backup *backup);
t_fd_backup		save_fds(void);
void			save_fds2(t_shell *shell);

// PID //
t_pid_list		*init_pid_list(void);
void			add_pid(t_pid_list *list, pid_t pid);
void			wait_all_pids(t_pid_list *list, t_exec *cmd);
void			free_pid_list(t_pid_list *list);

/* Builtins */
int				is_builtin(char *command);
void			ft_cd(t_env *env, char **args);
void			ft_echo(char **execs, t_shell *shell); ///kenny
void			ft_env(t_env_node *env);
void			ft_exit(t_shell *shell, char **args);
void			ft_mshell(t_shell *shell, char **cmd);
void			ft_pwd(void);
void			ft_export(char **args);
int				unset(t_shell *shell, char **execs);
void			handle_export(t_shell *shell, char **execs);
void			execute_builtin(t_shell *shell, t_exec *cmd);
void			handle_builtin(t_shell *shell, t_exec *exec_node);
void			exporting(t_shell *shell, char *str);

/* Execution */
t_exec			*create_exec_list(t_shell *shell);
t_exec			*create_exec_node(int id);
char			**tab_command(t_exec_context *context);
void			init_exec_context(t_exec_context *context, t_shell *shell);
void			execute_command(t_exec *node, t_env *env_lis, t_shell *shell);
void			fork_external(t_exec *head, t_env *env_list, t_shell *shell);
void			fork_builtin(t_shell *shell, t_exec *head, t_env *env_list);
void			send_to_exec(t_shell *shell, t_exec *cmd, t_env *env_list);
void			redirect_pid(int fd, int std_fd, const char *err_msg);
void			execute_exec_list(t_shell *shell, t_exec *cmd_list, t_env *env);
void			error_command(const char *message);
void			command_not_found(char *cmd, t_shell *shell);
char			*get_path(char *cmd, t_env *env_list);
void			handle_input(t_shell *shell);

int				check_pipe_validity(t_exec_context *context);
t_exec			*handle_exec_creation(t_shell *shell, t_exec_context *context);
int				process_lexer_node(t_shell *shell, t_exec_context *context);
void			update_exec_links(t_exec_context *context, t_exec *exec_node);

/* Redirection */
void			handle_redirection(t_shell *shell, t_exec_context *context);
void			handle_truncate_redirection(t_exec *node, t_token_list *current);
void			handle_append_redirection(t_exec *node, t_token_list *current);
void			handle_input_redirection(t_exec *node, t_token_list *current);
void			handle_here_redir(t_exec *node, t_token_list *current, t_shell *shell);
void			link_exec_with_pipe(t_exec *node_exec, t_exec_context *context);
void			int_to_string(int n, char *buffer, size_t size);

char			*clean_rl(char *rl_copy);
char			**input_split(const char *s);
t_shell			*init_shell(char **envp);

///////////       RANDOMS              ///////////

// t_exp			*init_exp(char *str);
// void			free_exp(t_exp *exp);
// int				handle_char(t_exp *exp, char c);
char			*ft_join_exp(char *s1, char *s2);
int				is_valid(char *arg);
int				ext_val(char *arg, t_env_node *node);
char			*ft_join_char(char *s, char c);
// int				expand_var(t_shell *shell, char **s, t_exp *exp, int i);
int				is_valid_id(char *arg);
int				create_add(t_shell *shell, char *args);
int				exp_no_args(t_env *env);
char			*ext_key(char *str, int *pos);
void			existing_node(t_env_node *node, char *arg, int pos);
void			new_node2(t_env *env, char *key, char *arg, int pos);
int				count_env_nodes(t_env *env);

//utils
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strndup(char *s, int i);
char			*ft_strncpy(char *s1, char *s2, int len);
void			reset_shell(t_shell *shell);
int				is_valid(char *arg);
int				is_valid_id(char *arg);
char	*ft_strjoin2(char const *s1, char const *s2);

/* Safe Functions */
void			*safe_malloc(size_t bytes);
void			ft_reset_std(t_exec *data);
void			error_exit(const char *msg);
void			safe_pid(pid_t pid);
void			safe_pipe(int pipefd[2]);


/* Sorting */
t_pair			*create_env_array(t_env *env, int count);
void			sort_env_array(t_pair *pairs, int count);
void			print_env_array(t_pair *pairs, int count);
void			free_env_arr(t_pair *pairs, int count);

/* Free Functions */
void			free_exec_node(t_exec *node);
void			free_exec(t_exec *list);
void			free_exec_list(t_exec *head);
void			free_heap(t_shell *shell);
void			free_tab(char **tab);
t_token_list	*free_lex(t_token_list *lex_head);
void			free_env(t_env *env);


/* Signals */
void			ft_signal(int sig);
int				*get_status();


#endif
