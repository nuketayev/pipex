# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 20:03:10 by anuketay          #+#    #+#              #
#    Updated: 2024/06/30 16:04:53 by anuketay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG  = pipex

SRCS	= srcs/pipex.c srcs/utils.c srcs/execute.c
OBJS	= ${SRCS:.c=.o}

HEADER	= -Iincludes

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

%.o: %.c
	${CC} ${CFLAGS} ${HEADER} -c $< -o $@

all: ${PROG}

${PROG}: ${OBJS}
	@make -C ./libft
	@${CC} ${OBJS} -Llibft -lft -o ${PROG}

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${PROG}

re: fclean all

.PHONY: all clean fclean re
