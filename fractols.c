/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:12:45 by maragao           #+#    #+#             */
/*   Updated: 2022/11/22 17:16:56 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	interations(t_vars *vars)
{
	double	z_temp;

	vars->interation = 0;
	while (vars->interation < 150)
	{
		z_temp = vars->z.re;
		vars->z.re = ((vars->z.re * vars->z.re)	- (vars->z.im * vars->z.im)) + vars->c.re;
		vars->z.im = (2 * z_temp * vars->z.im) + vars->c.im;
		if (((vars->z.re * vars->z.re) + (vars->z.im * vars->z.im)) > 4)
			break ;
		vars->interation++;
	}
	return (vars->interation);
}

int	interations_bs(t_vars *vars)
{
	double	z_temp;

	vars->interation = 0;
	while (vars->interation < 150)
	{
		z_temp = vars->z.re;
		vars->z.re = ((vars->z.re * vars->z.re)
				- (vars->z.im * vars->z.im)) + vars->c.re;
		vars->z.im = (fabs(2 * z_temp * vars->z.im)) + vars->c.im;
		if (((vars->z.re * vars->z.re) + (vars->z.im * vars->z.im)) > 4)
			break ;
		vars->interation++;
	}
	return (vars->interation);
}

int	mandelbrot(t_vars *vars)
{
	vars->y = 0;
	while (vars->y < SIZE_WIN)
	{
		vars->x = 0;
		vars->c.im = vars->key_y + (vars->y - SIZE_WIN / 2.0)
			* 4.0 / (SIZE_WIN / vars->zoom);
		while (vars->x < SIZE_WIN)
		{
			vars->c.re = vars->key_x + (vars->x - SIZE_WIN / 2.0)
				* 4.0 / (SIZE_WIN / vars->zoom);
			vars->z.re = 0;
			vars->z.im = 0;
			vars->interation = interations(vars);
			if (vars->interation != 150)
				put_color(vars);
			vars->x++;
		}
		vars->y++;
	}
	return (0);
}

int	julia(t_vars *vars)
{
	vars->y = 0;
	while (vars->y < SIZE_WIN)
	{
		vars->x = 0;
		while (vars->x < SIZE_WIN)
		{
			vars->z.im = vars->key_y + (vars->y - SIZE_WIN / 2.0) * 4.0 / (SIZE_WIN / vars->zoom);
			vars->z.re = vars->key_x - (vars->x - SIZE_WIN / 2.0) * 4.0 / (SIZE_WIN / vars->zoom);
			vars->interation = interations(vars);
			if (vars-> interation != 150)
				put_color(vars);
			vars-> x++;
		}
		vars-> y++;
	}
	return (0);
}

int	burning_ship(t_vars *vars)
{
	vars->y = 0;
	while (vars->y < SIZE_WIN)
	{
		vars->x = 0;
		vars->c.im = vars->key_y + (vars->y - SIZE_WIN / 2.0)
			* 4.0 / (SIZE_WIN / vars->zoom);
		while (vars->x < SIZE_WIN)
		{
			vars->c.re = vars->key_x + (vars->x - SIZE_WIN / 2.0)
				* 4.0 / (SIZE_WIN / vars->zoom);
			vars->z.re = 0;
			vars->z.im = 0;
			vars->interation = interations_bs(vars);
			if (vars->interation != 150)
				put_color(vars);
			vars->x++;
		}
		vars->y++;
	}
	return (0);
}
