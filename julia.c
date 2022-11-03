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

void	julia(t_vars vars)
{
	double	z_temp;

	vars.c.re = 0.285;
	vars.c.im = 0.01;
	vars.y = 0;
	while (vars.y < SIZE_WIN)
	{
		vars.x = 0;
		while (vars.x < SIZE_WIN)
		{
			vars.z.im = (vars.y - SIZE_WIN / 2.0) * 4.0 / (SIZE_WIN / vars.zoom);
			vars.z.re = (vars.x - SIZE_WIN / 2.0) * 4.0  / (SIZE_WIN / vars.zoom);
			vars.interation = 0;
			while (vars.interation < 1000)
			{
				z_temp = vars.z.re;
				vars.z.re = ((vars.z.re * vars.z.re) - (vars.z.im * vars.z.im)) + vars.c.re;
				vars.z.im = (2 * z_temp * vars.z.im) + vars.c.im;
				if (((vars.z.re * vars.z.re) + (vars.z.im * vars.z.im)) > 4)
					break;
				vars.interation++;
			}
			if (vars.interation != 1000)
				put_color(vars);
			vars.x++;
		}
		vars.y++;
	}
}
