/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:28:37 by maragao           #+#    #+#             */
/*   Updated: 2022/09/23 16:30:44 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*win_mlx;

	mlx_ptr = mlx_init();
	win_mlx = mlx_new_window(mlx_ptr, 600, 600,"tudo nos conformes");
	mlx_loop(mlx_ptr);

	return 0;
}
