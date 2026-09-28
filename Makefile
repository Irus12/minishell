NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

# ==================== SOURCES ====================

SRCS = builtins/export.c builtins/ft_echo.c builtins/ft_unset.c builtins/ft_pipe.c \
builtins/ft_pwd.c builtins/export_utils.c builtins/ft_env.c builtins/sort.c \
builtins/ft_cd.c main_init/grammar.c main_init/ft_exit.c main_init/handle_input.c \
main_init/minishell.c main_init/init_shell.c main_init/env_utils.c parsing/lexer_utils.c \
parsing/quote_remover_utils.c parsing/expander_utils.c parsing/token_list_utils.c \
parsing/is_builtins.c  parsing/expander.c parsing/expander2.c parsing/expander3.c parsing/parser.c \
parsing/lexer.c t_exec/exec_builtins.c t_exec/pid.c t_exec/exec_external_utils.c \
t_exec/exec_utils2.c t_exec/t_init_exec.c t_exec/signals_exec.c t_exec/handle_builtins.c \
t_exec/heredoc_utils.c t_exec/t_exec_creation2.c t_exec/heredoc_new_utils.c \
t_exec/exec_from_list.c t_exec/pipe.c t_exec/redirection.c t_exec/exec_externals.c \
t_exec/heredoc_exec.c t_exec/t_exec_creation.c t_exec/heredoc_new.c t_exec/exec_utils3.c \
t_exec/exec_utils.c utils/exit_status.c utils/shell_lexer_utils.c utils/utils2.c \
utils/utils1.c utils/signals.c utils/free_heap.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ==================== LIBFT ====================

LIBFT_DIR = libft_merged
LIBFT = $(LIBFT_DIR)/libft.a

# ==================== READLINE ====================

# *** AJOUTÉ ***
READLINE = -lreadline

# ==================== RULES ====================

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	# *** CHANGÉ : ajout de $(READLINE) ***
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE) -o $(NAME)

$(OBJ_DIR)/%.o: %.c minishell.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@ 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

test: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE) -I. -I$(LIBFT_DIR) -o test_parser

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test