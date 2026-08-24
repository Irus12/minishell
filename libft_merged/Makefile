# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romeo <romeo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/04 00:34:03 by romeo             #+#    #+#              #
#    Updated: 2026/02/04 00:36:15 by romeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = -Iinclude

SRCS = \
src/GNL/get_next_line.c \
src/GNL/get_next_line_utils.c \
src/libft/ft_atoi.c \
src/libft/ft_bzero.c \
src/libft/ft_calloc.c \
src/libft/ft_isalnum.c \
src/libft/ft_isalpha.c \
src/libft/ft_isascii.c \
src/libft/ft_isdigit.c \
src/libft/ft_isprint.c \
src/libft/ft_itoa.c \
src/libft/ft_lstadd_back.c \
src/libft/ft_lstadd_front.c \
src/libft/ft_lstclear.c \
src/libft/ft_lstdelone.c \
src/libft/ft_lstiter.c \
src/libft/ft_lstlast.c \
src/libft/ft_lstmap.c \
src/libft/ft_lstnew.c \
src/libft/ft_lstsize.c \
src/libft/ft_memchr.c \
src/libft/ft_memcmp.c \
src/libft/ft_memcpy.c \
src/libft/ft_memmove.c \
src/libft/ft_memset.c \
src/libft/ft_putchar_fd.c \
src/libft/ft_putendl_fd.c \
src/libft/ft_putnbr_fd.c \
src/libft/ft_putstr_fd.c \
src/libft/ft_split.c \
src/libft/ft_strchr.c \
src/libft/ft_strdup.c \
src/libft/ft_striteri.c \
src/libft/ft_strjoin.c \
src/libft/ft_strlcat.c \
src/libft/ft_strlcpy.c \
src/libft/ft_strlen.c \
src/libft/ft_strmapi.c \
src/libft/ft_strncmp.c \
src/libft/ft_strnstr.c \
src/libft/ft_strrchr.c \
src/libft/ft_strtrim.c \
src/libft/ft_substr.c \
src/libft/ft_tolower.c \
src/libft/ft_toupper.c \
src/printf/ft_printf.c \
src/printf/print_c.c \
src/printf/print_h.c \
src/printf/print_H.c \
src/printf/print_int.c \
src/printf/print_p.c \
src/printf/print_s.c \
src/printf/print_unsigned_int.c \
src/printf/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re