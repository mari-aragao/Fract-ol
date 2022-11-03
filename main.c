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
	t_vars	vars;

	(void)argv;
	(void)argc;
	vars.zoom = 1.0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SIZE_WIN, SIZE_WIN,"Fract'ol");
	vars.img= mlx_new_image(vars.mlx, SIZE_WIN, SIZE_WIN);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bpp, &vars.line_lenght, &vars.endian);
	set_hook(vars.win, &vars);
	mandelbrot(vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_loop(vars.mlx);

	return (0);
}
