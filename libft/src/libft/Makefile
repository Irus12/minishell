# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 15:41:55 by nschilli          #+#    #+#              #
#    Updated: 2025/11/03 15:53:18 by nschilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c \
		ft_toupper.c ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c \
		ft_strlcpy.c ft_strrchr.c ft_atoi.c ft_isascii.c ft_memcmp.c \
		ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
		ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c \
		ft_strmapi.c ft_substr.c ft_calloc.c ft_isprint.c ft_memmove.c \
		ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c
NAME := libft.a
OBJ := $(SRC:.c=.o)
RM := rm -f
CC := gcc -Wextra -Werror -Wall 

all: $(NAME)

$(NAME): $(OBJ) #crée archive
	ar rcs $@ $^
%.o: %.c #converti .c en .o
	$(CC) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re