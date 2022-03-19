SRCS = ./srcs/calc.c ./srcs/file.c ./srcs/main.c ./srcs/make_array.c ./srcs/memory.c ./srcs/one_param.c ./srcs/print_array.c ./srcs/read.c ./srcs/solution.c
OBJS    = ${SRCS:.c=.o}
NAME    = bsq
CC  = gcc
CFLAGS  = -Wall -Wextra -Wall
RM  = rm -f
INC = -I ./includes

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INC}

all:	${OBJS}
	${CC} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re