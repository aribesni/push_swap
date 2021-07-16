NAME = 		push_swap

SRC = 		main.c push_swap.c

CFLAG = 	-Wall -Wextra -Werror

CC = 		gcc

OBJS = 		${SRC:.c=.o}

LIB = 		./libft/libft.a

L_DIR = 	./libft/

all:		libft ${NAME}

libft:
			make -C ${L_DIR}

${NAME}:	${OBJS}
			${CC} ${CFLAG} ${OBJS} ${LIB} -o ${NAME}

clean:
			rm -f ${OBJS}
			make clean -C ${L_DIR}

fclean: 	clean
			rm -f ${NAME}
			make fclean -C ${L_DIR}

re: 		fclean all

.PHONY : 	all libft clean fclean re