# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 16:09:01 by rbordin           #+#    #+#              #
#    Updated: 2023/05/10 16:30:58 by rbordin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

PRINTF_PATH = ./ft_printf

PRINTF = $(PRINTF_PATH)/libftprintf.a

MAKEFLAGS += --silent

SRC = philo.c \
	utils.c \


OBJ = ${SRC:.c=.o}

CC = gcc -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

.o:.c
		${cc} ${CFLAGS} -c $< -o $@

all: ${NAME} 

${NAME}: ${OBJ} ${PRINTF}
		${CC} ${OBJ} ${PRINTF} -o ${NAME}
		@echo "\033[32mCompiled OK!\033[0m"

${PRINTF}:
		make -C ${PRINTF_PATH}		
		
clean:
		${RM} ${OBJ}
		make clean -C ${PRINTF_PATH}
		@echo "\033[35mCleaned everything!\033[0m"
		
fclean: clean

		${RM} ${PRINTF}
		${RM} ${NAME}

re: fclean all

