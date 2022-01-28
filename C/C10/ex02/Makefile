# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oronda <oronda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 15:58:21 by oronda            #+#    #+#              #
#    Updated: 2021/07/22 18:44:38 by oronda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC		= ft_tail.c

OBJS	= ${SRC:.c=.o}

NAME	= ft_tail

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
			
re:			fclean all

