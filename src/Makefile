# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 13:51:49 by vsanz-ar          #+#    #+#              #
#    Updated: 2023/01/20 15:13:57 by vsanz-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------------LIBFT MAKE VARS------------------------------------------------

LIBPATH = ../libft
LIBOB = ../libft/*.o

#----------------------------------------PRINTFT MAKE VARS------------------------------------------------
NAME = libftprintf.a
FILES = print_ft.c
CFLAGS = -Wall -Wextra -Werror 
CC = gcc
RM = rm -f
FOBJ = ${FILES:.c=.o}
#----------------------------------------PRINTFT MAKE RULES------------------------------------------------

all: ${NAME}

${NAME}:libft
	${CC} ${CFLAGS} -c ${FILES}  
	ar -rcs ${NAME} ${LIBOB} ${FOBJ}
	gcc main.c ${NAME}

clean:
	${RM} ${FOBJ} ${BOBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

#----------------------------------------LIBFT MAKE RULES------------------------------------------------

libft:
	make -C ${LIBPATH} 

.PHONY: all clean re fclean bonus libft 

