/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:18:04 by maragao           #+#    #+#             */
/*   Updated: 2022/10/27 18:20:56 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# define SIZE_WIN	800	


typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp; //bits per pixel
	int		line_lenght;
	int		endian;
	double	zoom;
}				t_data;

void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int		exit_hook(void *img);
int		key_press_hook(int key, void *img);
void	set_hook(void *win_mlx, t_data *img);
void	put_color(t_data img, int x, int y, int interation);
void	mandelbrot(t_data img);
void	julia(t_data img);
void	burning_ship(t_data img);
int		main(int argc, char	**argv);

#endif

