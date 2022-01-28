# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oronda <oronda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 15:58:29 by oronda            #+#    #+#              #
#    Updated: 2021/07/22 16:40:39 by oronda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_cat.c

OBJS	= ${SRC:.c=.o}

NAME	= ft_cat

CC 		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
					${CC} ${OBJS} -o ${NAME} 
					

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re :		fclean all 

