/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:15:04 by maragao           #+#    #+#             */
/*   Updated: 2022/11/24 21:16:37 by maragao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	error_msg(void)
{
	write(1, "Examples of valid arguments:\n", 29);
	write(1, "mandelbrot\n", 11);
	write(1, "julia 0.285 0.01\n", 17);
	write(1, "julia -0.8 0.156\n", 17);
	write(1, "julia -0.835 -0.2321\n", 21);
	write(1, "julia -1.037 0.17\n", 18);
	write(1, "julia -0.52 0.57\n", 17);
	write(1, "julia 0.285 0.50\n", 17);
	write(1, "\"burning ship\"\n", 15);
	return (-5);
}
