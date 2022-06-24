NAME			=	pipex
CC				= 	gcc
RM				= 	rm -rf
CFLAGS 			= 	-Wall -Wextra -Werror -g
LIBFT 			=	libft.a
AR				= 	ar rcs

SRCS	=	pipex.c					\
			utils.c					\
			free.c					\
	
OBJS	= ${SRCS:.c=.o}
%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< -I$

$(NAME):	${OBJS}
			make -C libft
			mv libft/libft.a .
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBFT}
			mv libft.a libft

all:	${NAME}

clean:
		${RM} ${OBJS} ${LIBFT} libft/libft.a
fclean: clean
		${RM} ${NAME} ${LIBFT} libft/libft.a
re:		fclean all
.PHONY:	all clean fclean re