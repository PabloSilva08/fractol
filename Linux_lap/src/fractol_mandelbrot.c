/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:50:08 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/24 16:26:22 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	set_mandelbrot(t_data *frac)
{
	double	x;
	double	y;
	double	next_x;
	double	next_y;

	x = 0;
	y = 0;
	frac->iteration = 0;
	while (x * x + y * y <= 4 && frac->iteration < MAX_ITERAC)
	{
		next_x = x * x - y * y + frac->c_x;
		next_y = 2 * x * y + frac->c_y;
		x = next_x;
		y = next_y;
		frac->iteration++;
	}
}

void	pre_mandelbrot(t_data *frac)
{
	int	x;
	int	y;

	y = 0;
	while (y < (HEIGHT))
	{
		x = 0;
		frac->c_y = (frac->im_max - (y * frac->unit_y));
		while (x < WIDTH)
		{
			frac->c_x = frac->re_min + x * frac->unit_x;
			set_mandelbrot(frac);
			if (frac->iteration == 300)
				my_mlx_pixel_put(frac, x, y, 0x00000000);
			else
				my_mlx_pixel_put(frac, x, y, frac->iteration * 0x00F0F8FF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frac->mlx, frac->mlx_win, frac->img, 0, 0);
}
