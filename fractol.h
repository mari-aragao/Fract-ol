/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:18:04 by maragao           #+#    #+#             */
/*   Updated: 2022/11/04 17:35:01 by maragao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define SIZE_WIN	800	


typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int	bpp;
	int	line_lenght;
	int	endian;
	int	validation;	
	t_complex	c;
	t_complex	z;
	int	x;
	int	y;
	int	interation;
	double	key_x;
	double	key_y;
	double	zoom;
}				t_vars;

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int	exit_hook(t_vars *vars);
int	key_press_hook(int key, t_vars *vars);
void	set_hook(void *win, t_vars *vars);
void	put_color(t_vars *vars);
int	ft_strcmp(char *s1, char *s2);
double	ft_atod(char *s);
int	mandelbrot(t_vars *vars);
int	julia(t_vars *vars);
int	burning_ship(t_vars *vars);
void	init_window(t_vars *vars);
int	validation(int argc, char **argv, t_vars *vars);
int	render_fractol(t_vars *vars);
int	main(int argc, char	**argv);
int	error_msg(void);


#endif

/*
validation = 1 -> mandelbrot
validation = 2 -> julia
validation = 3 -> burning ship
*/

