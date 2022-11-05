/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:17:09 by maragao           #+#    #+#             */
/*   Updated: 2022/11/04 16:59:54 by maragao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, SIZE_WIN, SIZE_WIN, "Fract'ol");
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dest;

	dest = vars->addr + (y * vars -> line_lenght + x * (vars -> bpp / 8));
	*(unsigned int *)dest = color;
}

int	validation(int argc, char **argv, t_vars *vars)
{
	if (argc == 2 && (ft_strcmp(argv[1], "mandelbrot") == 0))
		vars->validation = 1;
	else if (argc == 4 && (ft_strcmp(argv[1], "julia") == 0)
		&& ft_atod(argv[2]) != -1 && ft_atod(argv[3]) != -1)
	{
		vars->validation = 2;
		vars->c.re = ft_atod(argv[2]);
		vars->c.im = ft_atod(argv[3]);
	}
	else if (argc == 2 && (ft_strcmp(argv[1], "burning ship") == 0))
		vars->validation = 3;
	else
		return (error_msg());
	return (0);
}

int	render_fractol(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, SIZE_WIN, SIZE_WIN);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp,
			&vars->line_lenght, &vars->endian);
	if (vars->validation == 1)
		mandelbrot(vars);
	if (vars->validation == 2)
		julia(vars);
	if (vars ->validation == 3)
		burning_ship(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
