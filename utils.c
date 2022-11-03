/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:11:04 by maragao           #+#    #+#             */
/*   Updated: 2022/10/27 18:11:50 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] != 0 && s1[i] == s2[i])
		i++;
	return(s1[i] - s2[i]);
}

double	ft_atod(char *s)
{
	int i;
	int len;	
	double	res;
	
	i = 0;
	while (s[i] != 0)
	{
		if ((s[i] >= '0' && s[i]<= '9') || s[i] == '.' || s[0] == '-')
			i++;
		else
			return(-1);
	}
	len = 0;
	while (s[len] != 0)
		len++;
	res = 0.0;
	i = 2;
	if (s[0] == '-')
		i++;
	while (i < len)
		res = res * 10 + (s[i++] - '0');
	if (s[0] == '-')
	{
		res = -res;
		len--;
	}
	while (--len > 1)
		res = res / 10;
	if (s[0] >= '0' && s[0] <= '9')
		res = res + (s[0] - '0');
	if (s[1] >= '0' && s[1] <= '9')
		res = res + (s[1] - '0');
	return(res);
}


void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dest;

	dest = vars->addr + (y * vars -> line_lenght + x * (vars -> bpp / 8));
	*(unsigned int *)dest = color;
}
