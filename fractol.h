/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:18:04 by maragao           #+#    #+#             */
/*   Updated: 2022/10/25 20:09:02 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# define SIZE_WIN	800	


typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp; //bits per pixel
	int		line_lenght;
	int		endian;
	double	zoom;
}				t_data;

#endif
