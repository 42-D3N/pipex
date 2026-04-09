# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 14:56:37 by tle-pape          #+#    #+#              #
#    Updated: 2024/11/29 09:51:37 by tle-pape         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCEF = 	src/libft/checks/ft_isalnum.c src/libft/checks/ft_isalpha.c \
		src/libft/checks/ft_isascii.c src/libft/checks/ft_isdigit.c \
		src/libft/checks/ft_isprint.c \
		src/libft/lst/ft_lstadd_back.c src/libft/lst/ft_lstadd_front.c \
		src/libft/lst/ft_lstclear.c src/libft/lst/ft_lstdelone.c \
		src/libft/lst/ft_lstiter.c src/libft/lst/ft_lstlast.c \
		src/libft/lst/ft_lstmap.c src/libft/lst/ft_lstnew.c \
		src/libft/lst/ft_lstsize.c \
		src/libft/memmanip/ft_memchr.c src/libft/memmanip/ft_memcmp.c \
		src/libft/memmanip/ft_memcpy.c src/libft/memmanip/ft_memmove.c \
		src/libft/memmanip/ft_memset.c \
		src/libft/printer/ft_putchar_fd.c \
		src/libft/printer/ft_putendl_fd.c \
		src/libft/printer/ft_putnbr_fd.c \
		src/libft/printer/ft_putstr_fd.c \
		src/libft/struse/ft_calloc.c src/libft/struse/ft_strmapi.c \
		src/libft/struse/ft_strdup.c src/libft/struse/ft_strjoin.c \
		src/libft/struse/ft_strrchr.c src/libft/struse/ft_atoi.c \
		src/libft/struse/ft_strlcpy.c src/libft/struse/ft_itoa.c \
		src/libft/struse/ft_strnstr.c src/libft/struse/ft_split.c \
		src/libft/struse/ft_strlcat.c src/libft/struse/ft_strlen.c \
		src/libft/struse/ft_strncmp.c src/libft/struse/ft_substr.c \
		src/libft/struse/ft_toupper.c src/libft/struse/ft_strchr.c \
		src/libft/struse/ft_striteri.c src/libft/struse/ft_bzero.c \
		src/libft/struse/ft_tolower.c src/libft/struse/ft_strtrim.c \
		src/printf/ft_printf.c src/printf/ft_checkformat.c \
		src/printf/printfsrc/ft_r_print_hex.c \
		src/printf/printfsrc/ft_r_putnbr.c  \
		src/printf/printfsrc/ft_r_putptr.c \
		src/printf/printfsrc/ft_r_putstr.c \
		src/printf/printfsrc/ft_r_unsigned_dec.c \
		src/gnl/gnl.c
		

OBJS = ${SOURCEF:.c=.o}

NAME = libft.a

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}
	
clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -I include -o $@

.PHONY : all clean fclean re
