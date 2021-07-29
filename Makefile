# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 17:56:21 by aribesni          #+#    #+#              #
#    Updated: 2021/07/22 17:56:23 by aribesni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		push_swap

SRC = 		main.c operations.c push_swap.c push_swap_utils.c

SRCS = 		$(addprefix ./srcs/, $(SRC))

CFLAG = 	-Wall -Wextra -Werror

CC = 		gcc

OBJS = 		${SRCS:.c=.o}

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
