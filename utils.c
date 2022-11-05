/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:11:04 by maragao           #+#    #+#             */
/*   Updated: 2022/11/04 17:04:13 by maragao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	isneg;

	i = 0;
	res = 0;
	isneg = 0;
	if (nptr[i] == '-')
	{
		isneg = 1;
		i++;
	}
	while (nptr[i] != 0 && (nptr[i] >= '0' && nptr[i] <= '9'))
		res = (res * 10) + (nptr[i++] - '0');
	if (isneg == 1)
		res = -res;
	return (res);
}

int	atod_check(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[0] == '-')
			i++;
		else
			return (-1);
	}
	return (0);
}

double	ft_atod(char *s)
{
	int		i;
	int		len;
	double	res;
	double	dec;

	if (atod_check(s) == -1)
		return (-1);
	res = ft_atoi(s);
	i = 0;
	while (s[i] != 0 && s[i] != '.')
		i++;
	len = 0;
	if (s[i] == '.')
	{
		i++;
		dec = ft_atoi(&s[i]);
		while (s[i++] != 0)
			len++;
	}
	while (len-- > 0)
		dec /= 10;
	return (res + dec);
}
