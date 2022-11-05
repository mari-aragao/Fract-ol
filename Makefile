SRCS	= main.c color.c hook.c fractols.c utils.c render.c error.c

OBJS	= ${SRCS:.c=.o}

NAME	= fractol

FLAGSMLX	= -L mlx -lmlx -Ofast -framework OpenGL -framework AppKit

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	all

all:	${OBJS}
	cd mlx && make &> /dev/null
	cc ${CFLAGS} ${OBJS} ${FLAGSMLX} -o ${NAME}

clean:
	rm -rf ${OBJS}
	cd mlx && rm -rf *.o

fclean:	clean
	rm -rf ${NAME}
	cd mlx && rm -rf libmlx.a

re:	fclean all

.PHONY:	re fclean clean all
