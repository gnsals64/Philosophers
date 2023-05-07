# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 16:54:20 by hunpark           #+#    #+#              #
#    Updated: 2023/05/07 13:54:22 by hupa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAG = -Wall -Werror -Wextra #-fsanitize=thread
SRC_FILE = $(addprefix src/, main utils init thread_utils dine dine_utils monitor free share)
SRCS = ${SRC_FILE:=.c}
OBJS = ${SRC_FILE:=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@${CC} ${FLAG}  ${SRCS} -lpthread -o ${NAME}

clean :
	@rm -f ${OBJS}

fclean :
	@rm -f ${OBJS}
	@rm -f ${NAME}

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re
