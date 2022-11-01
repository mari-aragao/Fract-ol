/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:15:05 by maragao           #+#    #+#             */
/*   Updated: 2022/10/27 18:15:27 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_hook(void *img)
{
	(void)img;
	exit(0);
}

int	key_press_hook(int key, void *img)
{
	if(key == 53)
		exit_hook(img);
	return (0);
}

void	set_hook(void *win_mlx, t_data *img)
{
	mlx_hook(win_mlx, 2, 0, key_press_hook, img);
	mlx_hook(win_mlx, 17, 0, exit_hook, img);
}
