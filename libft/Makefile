# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 15:41:55 by nschilli          #+#    #+#              #
#    Updated: 2026/05/26 00:01:00 by nschilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_LIBFT := ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c \
		ft_toupper.c ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c \
		ft_strlcpy.c ft_strrchr.c ft_atoi.c ft_isascii.c ft_memcmp.c \
		ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
		ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c \
		ft_strmapi.c ft_substr.c ft_calloc.c ft_isprint.c ft_memmove.c \
		ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c
		
SRC_PRINTF := ft_printf.c ft_print_adress.c ft_putchar.c ft_puthex_low.c \
		ft_puthex_upp.c ft_putnbr.c ft_putstr.c ft_putunbr.c

SRC_GNL := get_next_line.c

LIBFT_DIR := src/libft/
PRINTF_DIR := src/ft_printf/
GNL_DIR := src/get_next_line/

SRC := $(addprefix $(LIBFT_DIR), $(SRC_LIBFT)) \
		$(addprefix $(PRINTF_DIR), $(SRC_PRINTF)) \
		$(addprefix $(GNL_DIR), $(SRC_GNL))

NAME := libft.a
OBJ := $(SRC:.c=.o)
RM := rm -f
CC := gcc -Wextra -Werror -Wall -Iinclude
 
all: $(NAME)

$(NAME): $(OBJ) #create archive
	ar rcs $@ $^
%.o: %.c #convert .c en .o
	$(CC) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re