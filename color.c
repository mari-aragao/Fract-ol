/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:12:02 by maragao           #+#    #+#             */
/*   Updated: 2022/10/27 18:12:32 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int	color(int i)
{
	int n;

	n = 3;
	while (--n >= 1)
		i = (i * 27) / n;
	return(i); 
}
void	put_color(t_vars vars)
{
	my_mlx_pixel_put(&vars, vars.x, vars.y, color(vars.interation));
}
