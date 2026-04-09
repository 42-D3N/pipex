# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapo <rapo@rapo.rapo>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 14:56:37 by tle-pape          #+#    #+#              #
#    Updated: 2025/01/17 10:43:57 by tle-pape         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCEF = src/main.c src/utils.c src/init.c src/pipe_exec.c

OBJS = ${SOURCEF:.c=.o}

NAME = libpipex.a

PROGNAME = pipex

all: ${NAME}

${NAME}: ${OBJS}
	cd ./libft && make
	cp ./libft/libft.a .
	mv libft.a ${NAME}
	ar -rcs ${NAME} ${OBJS}
	gcc ./src/*.c ${NAME}
	mv ./a.out ${PROGNAME}
	
clean:
	cd ./libft && make clean
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	cd ./libft && make fclean
	rm -f ${NAME}
	rm -f ${PROGNAME}

re: fclean all
	cd ./libft && make re

%.o: %.c
	gcc -Wall -Wextra -Werror -g -c $< -I include -o $@

.PHONY : all clean fclean re
