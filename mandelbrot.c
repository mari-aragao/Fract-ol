/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:12:45 by maragao           #+#    #+#             */
/*   Updated: 2022/10/27 18:13:23 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_data img)
{
	t_complex	c;
	t_complex	z;
	int y;
	int x;
	int interation;
	double	z_temp;

	y = 0;
	while (y < SIZE_WIN)
	{
		x = 0;
		c.im = (y - SIZE_WIN / 2.0) * 4.0 / (SIZE_WIN / img.zoom);
		while (x < SIZE_WIN)
		{
			c.re = (x - SIZE_WIN / 2.0) * 4.0  / (SIZE_WIN / img.zoom);
			z.re = 0;
			z.im = 0;
			interation = 0;
			while (interation < 1000)
			{
				z_temp = z.re;
				z.re = ((z.re * z.re) - (z.im * z.im)) + c.re;
				z.im = (2 * z_temp * z.im) + c.im;
				if (((z.re * z.re) + (z.im * z.im)) > 4)
					break;
				interation++;
			}
			if (interation != 1000)
				put_color(img, x, y, interation);
			x++;
		}
		y++;
	}
}
