/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:13:35 by maragao           #+#    #+#             */
/*   Updated: 2022/10/27 18:14:07 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_data img)
{
	t_complex	c;
	t_complex	z;
	int y;
	int x;
	int interation;
	double	z_temp;

	c.re = 0.285;
	c.im = 0.01;
	y = 0;
	while (y < SIZE_WIN)
	{
		x = 0;
		while (x < SIZE_WIN)
		{
			z.im = (y - SIZE_WIN / 2.0) * 4.0 / (SIZE_WIN / img.zoom);
			z.re = (x - SIZE_WIN / 2.0) * 4.0  / (SIZE_WIN / img.zoom);
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
