/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:15:05 by maragao           #+#    #+#             */
/*   Updated: 2022/11/04 21:55:13 by maragao          ###   ########.fr       */
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
		vars->key_x -= 0.2 * vars->zoom;
	else if (key == 124)
		vars->key_x += 0.2 * vars->zoom;
	else if (key == 125)
		vars->key_y += 0.2 * vars->zoom;
	else if (key == 126)
		vars->key_y -= 0.2 * vars-> zoom;
	else if (key == 53)
		exit_hook(vars);
	mlx_destroy_image(vars->mlx, vars->img);
	render_fractol(vars);
	return (0);
}

#include <stdio.h>
int	mouse_hook(int key, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (key == 4)
		vars->zoom += 0.1 * vars->zoom;
	if (key == 5)
		vars->zoom -= 0.1 * vars->zoom;
	mlx_destroy_image(vars->mlx, vars->img);
	render_fractol(vars);
	return (0);

}

void	set_hook(void *win, t_vars *vars)
{
	mlx_key_hook(win, key_press_hook, vars);
	mlx_mouse_hook(win, mouse_hook, vars);
	mlx_hook(win, 17, 0, exit_hook, vars);
}
