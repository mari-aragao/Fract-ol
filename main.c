/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:17:12 by maragao           #+#    #+#             */
/*   Updated: 2022/11/04 16:22:10 by maragao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.zoom = 1.0;
	vars.key_x = 0.0;
	vars.key_y = 0.0;
	if (validation(argc, argv, &vars) == -1)
		return (0);
	init_window(&vars);
	set_hook(vars.win, &vars);
	render_fractol(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
