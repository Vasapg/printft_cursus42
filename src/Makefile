# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 13:51:49 by vsanz-ar          #+#    #+#              #
#    Updated: 2023/04/04 10:36:24 by vsanz-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------------LIBFT MAKE VARS------------------------------------------------

LIBPATH = ./libft
LIBA = ./libft/libft.a

#----------------------------------------PRINTFT MAKE VARS------------------------------------------------
NAME = libftprintf.a
FILES = print_ft.c print_ft_utils.c
CFLAGS = -Wall -Wextra -Werror 
CC = gcc
RM = rm -f
FOBJ = ${FILES:.c=.o} 
#----------------------------------------PRINTFT MAKE RULES------------------------------------------------

all: ${NAME}

${NAME}: ${FOBJ}
	@make -C ${LIBPATH}
	@cp libft/libft.a .
	@mv libft.a ${NAME}
	ar -rcs ${NAME} ${FOBJ}

clean:
	@make clean -C ${LIBPATH}
	${RM} ${FOBJ} ${BOBJ} test.out

fclean: clean
	${RM} ${LIBA}
	${RM} ${NAME}

re: fclean all

#----------------------------------------LIBFT MAKE RULES-----------------------------------------------

.PHONY: all clean re fclean bonus libft 

