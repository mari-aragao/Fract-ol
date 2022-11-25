/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:15:04 by maragao           #+#    #+#             */
/*   Updated: 2022/11/24 19:50:53 by maragao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	error_msg(void)
{
	write(1, "Example of valid argument:\n", 27);
	write(1, "mandelbrot\n", 11);
	write(1, "julia 0.285 0.01\n", 17);
	write(1, "julia -0.8 0.156\n", 17);
	write(1, "julia -0.835 -0.2321\n", 21);
	write(1, "\"burning ship\"\n", 15);
	return (-5);
}
