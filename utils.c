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

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img -> line_lenght + x * (img -> bpp / 8));
	*(unsigned int *)dest = color;
}
