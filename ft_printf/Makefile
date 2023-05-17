# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 14:46:04 by rbordin           #+#    #+#              #
#    Updated: 2023/02/16 16:39:19 by rbordin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ${NAME:.a=.h}

SOURCES = ft_printf.c \
ft_print_utils.c \
ft_print_needed.c \

OBJECTS = ${SOURCES:.c=.o}

CC = GCC

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.o:.c
	${CC} ${CFLAGS} ${OBJECTS} $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}
	

all:	${NAME}

clean:
		${RM} ${OBJECTS}

fclean: clean
		${RM} ${NAME}

re: fclean all
