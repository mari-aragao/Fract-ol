/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:14:26 by maragao           #+#    #+#             */
/*   Updated: 2022/11/03 19:15:01 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(t_vars *vars) 
{
	double	z_temp;

	vars -> y = 0;
	while (vars -> y < SIZE_WIN)
	{
		vars -> x = 0;
		vars -> c.im = (vars -> y - SIZE_WIN / 2.0) * 4.0 / (SIZE_WIN / vars -> zoom);
		while (vars -> x < SIZE_WIN)
		{
			vars -> c.re = (vars -> x - SIZE_WIN / 2.0) * 4.0  / (SIZE_WIN / vars -> zoom);
			vars -> z.re = 0;
			vars -> z.im = 0;
			vars -> interation = 0;
			while (vars -> interation < 1000)
			{
				z_temp = vars -> z.re;
				vars -> z.re = ((vars -> z.re * vars -> z.re) - (vars -> z.im * vars -> z.im)) + vars -> c.re;
				vars -> z.im = (fabs(2 * z_temp * vars -> z.im)) + vars -> c.im;
				if (((vars -> z.re * vars -> z.re) + (vars -> z.im * vars -> z.im)) > 4)
					break;
				vars -> interation++;
			}
			if (vars -> interation != 1000)
				put_color(vars);
			vars -> x++;
		}
		vars -> y++;
	}
}

