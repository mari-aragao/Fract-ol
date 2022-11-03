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

int	exit_hook(void *vars)
{
	(void)vars;
	exit(0);
}

int	key_press_hook(int key, void *vars)
{
	if(key == 53)
		exit_hook(vars);
	return (0);
}

void	set_hook(void *win, t_vars *vars)
{
	mlx_hook(win, 2, 0, key_press_hook, vars);
	mlx_hook(win, 17, 0, exit_hook, vars);
}
