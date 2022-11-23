SRCS	= main.c color.c hook.c fractols.c utils.c render.c error.c

SRCS_BONUS	= bonus/main_bonus.c bonus/color_bonus.c bonus/hook_bonus.c bonus/fractol_bonus.c bonus/utils_bonus.c bonus/render_bonus.c bonus/error_bonus.c

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME	= fractol

bonus/NAME_BONUS	= fractol

FLAGSMLX	= -L mlx -lmlx -Ofast -framework OpenGL -framework AppKit

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	all

${NAME_BONUS}:	all_bonus

all:	${OBJS}
	cd mlx && make &> /dev/null
	cc ${CFLAGS} ${OBJS} ${FLAGSMLX} -o ${NAME}

all_bonus:	${OBJS_BONUS}
	cd bonus
	cd mlx && make &> /dev/null
	cc ${CFLAGS} ${OBJS_BONUS} ${FLAGSMLX} -o ${NAME_BONUS}
	
clean:
	rm -rf ${NAME}
	rm -rf ${NAME_BONUS}
	cd mlx
	rm -rf *.o

fclean:	clean
	rm -rf ${NAME}
	rm -rf ${NAME_BONUS}
	cd mlx
	rm -rf libmlx.a

bonus:	
	all_bonus

re:	fclean all

.PHONY:	re fclean clean all
