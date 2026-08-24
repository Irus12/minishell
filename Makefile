NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

# ==================== SOURCES ====================

# *** Wildcards ajoutés pour récupérer automatiquement les .c ***
SRCS = $(wildcard main_init/*.c) \
       $(wildcard exec/*.c) \
       $(wildcard parsing/*.c) \
       $(wildcard utils/*.c)

OBJS = $(SRCS:.c=.o)

# ==================== LIBFT ====================

# *** Ta libft_merged ***
LIBFT_DIR = libft_merged
LIBFT = $(LIBFT_DIR)/libft.a

# ==================== RULES ====================

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# *** minishell.h à la racine ***
%.o: %.c minishell.h
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

# *** Compile la libft avec son propre Makefile ***
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re