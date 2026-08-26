NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

# ==================== SOURCES ====================

SRCS = $(wildcard main_init/*.c) \
       $(wildcard parsing/*.c) \
       $(wildcard t_exec/*.c) \
	   $(wildcard builtins/*.c) \
       $(wildcard utils/*.c)

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

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re