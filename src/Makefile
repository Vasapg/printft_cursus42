# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 13:51:49 by vsanz-ar          #+#    #+#              #
#    Updated: 2023/01/26 14:04:02 by vsanz-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------------LIBFT MAKE VARS------------------------------------------------

LIBPATH = ./libft
LIBOB = ./libft/*.o #ARREGLAR ESTA WILDCARD AAAAA

#----------------------------------------PRINTFT MAKE VARS------------------------------------------------
NAME = libftprintf.a
FILES = print_ft.c print_ft_utils.c
CFLAGS = -Wall -Wextra -Werror 
CC = gcc
RM = rm -f
FOBJ = ${FILES:.c=.o}
#----------------------------------------PRINTFT MAKE RULES------------------------------------------------

all: ${NAME}

${NAME}: ${FOBJ} libft 
	ar -rcs ${NAME} ${LIBOB} ${FOBJ}

clean:
	${RM} ${FOBJ} ${BOBJ} test.out

fclean: clean
	${RM} ${NAME}

re: fclean all

#----------------------------------------LIBFT MAKE RULES------------------------------------------------

libft:
	make -C ${LIBPATH} 

.PHONY: all clean re fclean bonus libft 

