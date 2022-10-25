/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragao <maragao@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:28:37 by maragao           #+#    #+#             */
/*   Updated: 2022/10/01 19:36:36 by maragao          ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img -> line_lenght + x * (img -> bpp / 8));
	*(unsigned int *)dest = color;
}

int	exit_hook(void *img)
{
	(void)img;
	exit(0);
}

int	key_press_hook(int key, void *img)
{
	if(key == 53)
		exit_hook(img);
	return (0);
}
void	set_hook(void *win_mlx, t_data *img)
{
	mlx_hook(win_mlx, 2, 0, key_press_hook, img);
	mlx_hook(win_mlx, 17, 0, exit_hook, img);
}

void	put_color(t_data img, int x, int y, int interation)
{
			if (interation < 2)
				my_mlx_pixel_put(&img, x, y, 0x005452);
			if (interation >= 2 && interation < 3)
				my_mlx_pixel_put(&img, x, y, 0x006465);
			if (interation >= 3 && interation < 4)
				my_mlx_pixel_put(&img, x, y, 0x007476);
			if (interation >= 4 && interation < 6)
				my_mlx_pixel_put(&img, x, y, 0x008489);
			if (interation >= 6 && interation < 8)
				my_mlx_pixel_put(&img, x, y, 0x1C9997);
			if (interation >= 8 && interation < 12)
				my_mlx_pixel_put(&img, x, y, 0x48A3A7);
			if (interation >= 12 && interation < 20)
				my_mlx_pixel_put(&img, x, y, 0x7AB4AD);
			if (interation >= 20 && interation < 40)
				my_mlx_pixel_put(&img, x, y, 0x93C2C4);
			if (interation >= 40 && interation < 60)
				my_mlx_pixel_put(&img, x, y, 0xA4C9BB);
			if (interation >= 60 && interation < 90)
				my_mlx_pixel_put(&img, x, y, 0xB7D2B6);
			if (interation >= 90 && interation < 200)
				my_mlx_pixel_put(&img, x, y, 0xE1EDE0);
			if (interation >= 200 && interation < 1000)
				my_mlx_pixel_put(&img, x, y, 0xFFFFFF);

}
void	put_mandaobroto(t_data img)
{
	t_complex	c;
	t_complex	z;
	int y;
	int x;
	int interation;
	double	z_temp;

	y = 0;
	while (y < SIZE_WIN)
	{
		x = 0;
		c.im = 0 - (y - SIZE_WIN / 2.0) * 4.0 / SIZE_WIN;
		while (x < SIZE_WIN)
		{
			c.re = -0.4 + (x - SIZE_WIN / 2.0) * 4.0  / SIZE_WIN;
			z.re = 0;
			z.im = 0;
			interation = 0;
			while (interation < 1000)
			{
				z_temp = z.re;
				z.re = ((z.re * z.re) - (z.im * z.im)) + c.re;
				z.im = (2 * z_temp * z.im) + c.im;
				if (((z.re * z.re) + (z.im * z.im)) > 4)
					break;
				interation++;
			}
			if (interation != 1000)
				put_color(img, x, y, interation);
			x++;
		}
		y++;
	}
}

int main()
{
	void	*mlx_ptr;
	void	*win_mlx;
	t_data	img;

	mlx_ptr = mlx_init();
	win_mlx = mlx_new_window(mlx_ptr, SIZE_WIN, SIZE_WIN,"tudo nos conformes");
	img.img = mlx_new_image(mlx_ptr, SIZE_WIN, SIZE_WIN);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_lenght, &img.endian);
	set_hook(win_mlx, &img);	
	put_mandaobroto(img);
	mlx_put_image_to_window(mlx_ptr, win_mlx, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	
	return 0;
}
