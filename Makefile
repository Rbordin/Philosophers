# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 16:09:01 by rbordin           #+#    #+#              #
#    Updated: 2023/05/29 11:44:19 by rbordin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

MAKEFLAGS += --silent

SRC = philo.c \
	utils.c \
	setting.c \
	extra.c \

OBJ = ${SRC:.c=.o}

CC = gcc -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

.o:.c
		${CC} ${CFLAGS} -c $< -o $@

all: ${NAME} 

${NAME}: ${OBJ} 
		${CC} ${OBJ} -o ${NAME}
		@echo "\033[32mPhilosophers are ready to eat!\033[0m"

clean:
		${RM} ${OBJ}
		@echo "\033[35mDining table has been cleaned!\033[0m"
		
fclean: clean
		${RM} ${NAME}

re: fclean all
		@echo "\033[36mDining table is ready again!\033[0m"
