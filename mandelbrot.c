/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:12:45 by maragao           #+#    #+#             */
/*   Updated: 2022/11/03 20:18:40 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	mandelbrot(t_vars *vars) 
{
	double	z_temp;

	vars -> img = mlx_new_image(vars -> mlx, SIZE_WIN, SIZE_WIN);
	vars ->addr = mlx_get_data_addr(vars -> img, &vars -> bpp, &vars -> line_lenght, &vars -> endian);
	vars -> y = 0;
	while (vars -> y < SIZE_WIN)
	{
		vars -> x = 0;
		vars -> c.im = vars -> key_y - (vars -> y - SIZE_WIN / 2.0) * 4.0 / (SIZE_WIN / vars -> zoom);
		while (vars -> x < SIZE_WIN)
		{
			vars -> c.re = vars -> key_x + (vars -> x - SIZE_WIN / 2.0) * 4.0  / (SIZE_WIN / vars -> zoom);
			vars -> z.re = 0;
			vars -> z.im = 0;
			vars -> interation = 0;
			while (vars -> interation < 150)
			{
				z_temp = vars -> z.re;
				vars -> z.re = ((vars -> z.re * vars -> z.re) - (vars -> z.im * vars -> z.im)) + vars -> c.re;
				vars -> z.im = (2 * z_temp * vars -> z.im) + vars -> c.im;
				if (((vars -> z.re * vars -> z.re) + (vars -> z.im * vars -> z.im)) > 4)
				{
					my_mlx_pixel_put(vars, vars -> x, vars -> y, 0x00000000);
					break;
				}
				vars -> interation++;
			}
			if (vars -> interation != 150)
				put_color(vars);
			vars -> x++;
		}
		vars -> y++;
	}
	mlx_put_image_to_window(vars -> mlx, vars -> win, vars -> img, 0, 0);
	return 0;
}
