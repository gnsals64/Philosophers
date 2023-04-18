# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 16:54:20 by hunpark           #+#    #+#              #
#    Updated: 2023/04/18 20:45:36 by hunpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher
CC = cc
FLAG = -Wall -Werror -Wextra #-fsanitize=address
SRC_FILE = $(addprefix src/, main utils init)
SRCS = ${SRC_FILE:=.c}

all : ${NAME}

${NAME} :
	@${CC} ${FLAG} ${SRCS} -o ${NAME}

clean :

fclean :
	@rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
