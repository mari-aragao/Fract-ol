/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:11:04 by maragao           #+#    #+#             */
/*   Updated: 2022/10/27 18:11:50 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dest;

	dest = vars->addr + (y * vars -> line_lenght + x * (vars -> bpp / 8));
	*(unsigned int *)dest = color;
}
