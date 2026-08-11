SRCS = ft_printf.c ft_print_adress.c ft_putchar.c ft_puthex_low.c ft_puthex_upp.c ft_putnbr.c ft_putstr.c ft_putunbr.c ft_strlen.c

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -MMD -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar -rsc ${NAME} ${OBJS}

all: 	${NAME}

clean:	
		rm -f ${OBJS} ${DEPS}

fclean:	clean;
		rm -f ${NAME}

re:	fclean all

-include ${DEPS}

.PHONY: all clean fclean re
