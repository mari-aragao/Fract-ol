/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:15:04 by maragao           #+#    #+#             */
/*   Updated: 2022/11/22 17:49:48 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	error_msg(void)
{
		write(1, "Examples of valid arguments:\nmandelbrot\njulia 0.123 0.745\n\"burning ship\"\n", 73);
		return (-1);
}
