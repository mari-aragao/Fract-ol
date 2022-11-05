/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:15:05 by maragao           #+#    #+#             */
/*   Updated: 2022/11/04 17:08:27 by maragao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_hook(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_press_hook(int key, t_vars *vars)
{
	if (key == 123)
		vars->key_x += 0.2;
	else if (key == 124)
		vars->key_x -= 0.2;
	else if (key == 125)
		vars->key_y -= 0.2;
	else if (key == 126)
		vars->key_y += 0.2;
	else if (key == 53)
		exit_hook(vars);
	mlx_destroy_image(vars->mlx, vars->img);
	render_fractol(vars);
	return (0);
}

void	set_hook(void *win, t_vars *vars)
{
	mlx_key_hook(win, key_press_hook, vars);
	mlx_hook(win, 17, 0, exit_hook, vars);
}
