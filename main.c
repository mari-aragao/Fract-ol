/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:17:12 by maragao           #+#    #+#             */
/*   Updated: 2022/10/27 18:21:36 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window(t_vars *vars)
{
	vars -> mlx = mlx_init();
	vars -> win = mlx_new_window(vars -> mlx, SIZE_WIN, SIZE_WIN,"Fract'ol");
	vars -> img= mlx_new_image(vars -> mlx, SIZE_WIN, SIZE_WIN);
	vars ->addr = mlx_get_data_addr(vars -> img, &vars -> bpp, &vars -> line_lenght, &vars -> endian);
}

int	error_msg(void)
{
		write(1, "Examples of valid arguments:\nmandelbrot\njulia \"0.123\" \"0.745\"", 62);
		return (-1);		
}

int	validation(int argc, char **argv, t_vars *vars)
{
	if (argc == 1 || argc == 3) 
		return (error_msg());
	if (argc == 2 && (ft_strcmp(argv[1], "mandelbrot") != 0))
		return (error_msg());
	if (argc == 2 && (ft_strcmp(argv[1], "julia") == 0))
		return (error_msg());
	if (argc == 4 && (ft_strcmp(argv[1], "julia") != 0))  
		return (error_msg());
	if (argc == 2 && (ft_strcmp(argv[1], "mandelbrot") == 0))
		vars -> validation = 1;
	if (argc == 4 && (ft_strcmp(argv[1], "julia") == 0) && atof(argv[2]) != -1 && atof(argv[3]) != -1)
	{
		vars -> validation = 2;
		vars -> c.re = ft_atod(argv[2]);
		vars -> c.im = ft_atod(argv[3]);
	}
	return (0);		
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.zoom = 1.0;
	if (validation(argc, argv, &vars) == -1)
		return(0);
	init_window(&vars);
	set_hook(vars.win, &vars);
	if (vars.validation == 1)
		mandelbrot(vars);
	if (vars.validation == 2)
		julia(vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
