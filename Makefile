SRCS	= main.c

OBJS	= ${SRCS:.c=.o}

NAME	= fractoles

FLAGSMLX	= -L mlx -lmlx -framework OpenGL -framework AppKit

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	all

all:	${OBJS}
	cd mlx && make
	cc ${CFLAGS} ${OBJS} ${FLAGSMLX} -o ${NAME}

clean:
	rm -rf ${OBJS}
	cd mlx && rm -rf *.o

fclean:	clean
	rm -rf ${NAME}
	cd mlx && rm -rf libmlx.a

re:	fclean all

.PHONY:	re fclean clean all
