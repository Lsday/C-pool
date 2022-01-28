
SRC		= main.c ft_atoi.c ops.c put_nbr.c

OBJS	= ${SRC:.c=.o}

NAME	= do-op

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

