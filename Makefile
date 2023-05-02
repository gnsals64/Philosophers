# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 16:54:20 by hunpark           #+#    #+#              #
#    Updated: 2023/05/02 20:15:45 by hunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAG = -Wall -Werror -Wextra #-fsanitize=thread
SRC_FILE = $(addprefix src/, main utils init thread_utils dine dine_utils monitor)
SRCS = ${SRC_FILE:=.c}

all : ${NAME}

${NAME} :
	@${CC} ${FLAG} ${SRCS} -lpthread -o ${NAME}

clean :

fclean :
	@rm -f ${NAME}

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re
