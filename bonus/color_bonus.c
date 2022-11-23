/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:12:02 by maragao           #+#    #+#             */
/*   Updated: 2022/11/23 20:09:50 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	color(int i)
{
	int	n;

	n = 3;
	while (--n >= 1)
		i = (i * 3269) / 61;
	return (i);
}

void	put_color(t_vars *vars)
{
	my_mlx_pixel_put(vars, vars->x, vars->y, color(vars->interation));
}
