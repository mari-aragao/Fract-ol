NAME	= fractol

SRCS	=	\
		main.c \
		color.c \
		hook.c \
		fractol.c \
		utils.c \
		render.c \
		error.c

SRCS_B	=	\
		main_bonus.c \
		color.c \
		hook.c \
		fractol_bonus.c \
		utils.c \
		render_bonus.c \
		error_bonus.c

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}


MLX_FLAGS	= -L mlx -lmlx -Ofast -framework OpenGL -framework AppKit

CC	= -Wall -Wextra -Werror

.c.o:
	cc ${CC} -c $< -o ${<:.c=.o}

${NAME}:	all

all:	${OBJS}
	cd mlx && make &> /dev/null
	cc ${CC} ${OBJS} ${MLX_FLAGS} -o ${NAME}

bonus:	${OBJS_B}
	cd mlx && make &> /dev/null
	cc ${CC} ${OBJS_B} ${MLX_FLAGS} -o ${NAME}
	
clean:
	rm -rf ${OBJS}
	rm -rf ${OBJS_B}
	cd mlx && rm -rf *.o

fclean:	clean
	rm -rf ${NAME}
	rm -rf *.dSYM
	cd mlx && rm -rf libmlx.a

re:	fclean all

.PHONY:	re fclean clean all
