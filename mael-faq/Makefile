# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 17:09:10 by mael-faq          #+#    #+#              #
#    Updated: 2024/09/22 20:31:05 by pyarova          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = rush-02

SRC = $(wildcard src/*.c)

OBJS = ${SRC:.c=.o}

CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}
		
all:	${NAME}


clean:
		${RM} ${OBJS}


fclean: clean
		${RM} ${NAME}


re: fclean all

.PHONY: all clean fclean re
