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

void	put_color(t_data img, int x, int y, int interation)
{
			if (interation < 2)
				my_mlx_pixel_put(&img, x, y, 0x005452);
			if (interation >= 2 && interation < 3)
				my_mlx_pixel_put(&img, x, y, 0x006465);
			if (interation >= 3 && interation < 4)
				my_mlx_pixel_put(&img, x, y, 0x007476);
			if (interation >= 4 && interation < 6)
				my_mlx_pixel_put(&img, x, y, 0x008489);
			if (interation >= 6 && interation < 8)
				my_mlx_pixel_put(&img, x, y, 0x1C9997);
			if (interation >= 8 && interation < 12)
				my_mlx_pixel_put(&img, x, y, 0x48A3A7);
			if (interation >= 12 && interation < 20)
				my_mlx_pixel_put(&img, x, y, 0x7AB4AD);
			if (interation >= 20 && interation < 40)
				my_mlx_pixel_put(&img, x, y, 0x93C2C4);
			if (interation >= 40 && interation < 60)
				my_mlx_pixel_put(&img, x, y, 0xA4C9BB);
			if (interation >= 60 && interation < 90)
				my_mlx_pixel_put(&img, x, y, 0xB7D2B6);
			if (interation >= 90 && interation < 200)
				my_mlx_pixel_put(&img, x, y, 0xE1EDE0);
			if (interation >= 200 && interation < 1000)
				my_mlx_pixel_put(&img, x, y, 0xFFFFFF);

}
