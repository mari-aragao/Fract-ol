/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:17:12 by maragao           #+#    #+#             */
/*   Updated: 2022/10/27 18:21:36 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_mlx;
	t_data	img;

	(void)argv;
	(void)argc;
	img.zoom = 1.0;
	mlx_ptr = mlx_init();
	win_mlx = mlx_new_window(mlx_ptr, SIZE_WIN, SIZE_WIN,"tudo nos conformes");
	img.img = mlx_new_image(mlx_ptr, SIZE_WIN, SIZE_WIN);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_lenght, &img.endian);
	set_hook(win_mlx, &img);
	mandelbrot(img);
	mlx_put_image_to_window(mlx_ptr, win_mlx, img.img, 0, 0);
	mlx_loop(mlx_ptr);

	return 0;
}
