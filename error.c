/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:15:04 by maragao           #+#    #+#             */
/*   Updated: 2022/11/23 20:12:02 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	error_msg(void)
{
	write(1, "Examples of valid arguments:\nmandelbrot\n", 40);
	write(1, "julia 0.285 0.01\n", 17);
	write(1, "julia -0.8 0.156\n", 17);
	write(1, "julia -0.835 -0.2321\n", 21);
	return (-5);
}
