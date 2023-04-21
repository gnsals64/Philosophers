# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hupa <hupa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 16:54:20 by hunpark           #+#    #+#              #
#    Updated: 2023/04/22 02:22:39 by hupa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher
CC = cc
FLAG = -g -Wall -Werror -Wextra #-fsanitize=address
SRC_FILE = $(addprefix src/, main utils init thread_utils)
SRCS = ${SRC_FILE:=.c}

all : ${NAME}

${NAME} :
	@${CC} ${FLAG} ${SRCS} -lpthread -o ${NAME}

clean :

fclean :
	@rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
