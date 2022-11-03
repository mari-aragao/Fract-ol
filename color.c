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

void	put_color(t_vars vars)
{
			if (vars.interation < 2)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0x005452);
			if (vars.interation >= 2 && vars.interation < 3)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0x006465);
			if (vars.interation >= 3 && vars.interation < 4)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0x007476);
			if (vars.interation >= 4 && vars.interation < 6)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0x008489);
			if (vars.interation >= 6 && vars.interation < 8)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0x1C9997);
			if (vars.interation >= 8 && vars.interation < 12)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0x48A3A7);
			if (vars.interation >= 12 && vars.interation < 20)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0x7AB4AD);
			if (vars.interation >= 20 && vars.interation < 40)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0x93C2C4);
			if (vars.interation >= 40 && vars.interation < 60)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0xA4C9BB);
			if (vars.interation >= 60 && vars.interation < 90)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0xB7D2B6);
			if (vars.interation >= 90 && vars.interation < 200)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0xE1EDE0);
			if (vars.interation >= 200 && vars.interation < 1000)
				my_mlx_pixel_put(&vars, vars.x, vars.y, 0xFFFFFF);

}
