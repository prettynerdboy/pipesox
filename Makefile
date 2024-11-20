# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anakin <anakin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 18:33:53 by anakin            #+#    #+#              #
#    Updated: 2024/11/20 19:38:12 by anakin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pipex

SRCS    = src/pipex.c src/utility.c src/error.c
OBJS    = ${SRCS:.c=.o}

# HEADER  = -Iincludes

CC      = cc
CFLAGS  = -Wall -Wextra -Werror  -I ./Include 
# -g -fsanitize=address
LDFLAGS = -fsanitize=address

.c.o:
	${CC} ${CFLAGS}  -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	@make re -C ./libft
	@${CC} ${CFLAGS} ${LDFLAGS} ${OBJS} -Llibft -lft -o ${NAME}
	@echo "pipex Compiled"


clean:
	@make clean -C ./libft
	@rm -f ${OBJS} ${OBJS_B}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${NAME}
	@echo "Deleting EVERYTHING"

re: fclean all

.PHONY: all clean fclean re