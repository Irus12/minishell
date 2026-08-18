# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2026/08/11 00:00:00 by copilot            #+#    #+#              #
#    Updated: 2026/08/11 00:00:00 by copilot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell
CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

SRC := parsing/lexer.c parsing/expander.c parsing/expander_utils.c parsing/lexer_utils.c parsing/token_list_utils.c parser.c main.c exit_status.c
OBJ := $(SRC:.c=.o)

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
INCLUDES := -I. -I$(LIBFT_DIR)/include

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
