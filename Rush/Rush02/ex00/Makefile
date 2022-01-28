SRC		= ft_split.c parse_dict.c ft_split_mod.c main.c error_handler.c is_valid.c  

OBJS	= ${SRC:.c=.o}

NAME	= rush-02

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