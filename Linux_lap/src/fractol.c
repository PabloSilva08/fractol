/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:50:08 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/21 23:47:02 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	set_mandelbrot(t_data *frac)
{
	double		x;
	double		y;
	double	next_x;
	double	next_y;
	int		iteration;

	x = 0;
	y = 0;
	iteration = 0;
	while (x*x + y*y <= 4 && iteration < MAX_ITERAC)
	{
		printf("circ = %.1f\n", x*x + y*y);
		printf("x*x = %.1f\n", x*x);
		next_x = x*x - y*y + frac->c_x;
		next_y = 2*x*y + frac->c_y;
		x = next_x;
		y = next_y;
		iteration++;
	}
	return (iteration);
}

//void	choose_the_fractal(t_data *frac)
//{
//	int	color;
//
//	color = 0;
//	if (ft_strncmp(frac->argv[1], "mandelbrot", 10) == 0)
//		color = set_mandelbrot(c_x, c_y);
//	paiting(frac, c_x, c_y, color);
//}


void	pixel_coordinate_conversio(t_data *frac)
{
	int	iteration;
	int	x;
	int	y;

	iteration = 0;
	y = 0;
	while (y < (HEIGHT))
	{
		x = 0;
		frac->c_y = (frac->im_max - (y*frac->unit_y));
		while (x < WIDTH)
		{
			frac->c_x = frac->re_min + x*frac->unit_x;
			printf("(%d, %d) = (%.3f, %.3f)\n",x, y, frac->c_x, frac->c_y);
			iteration = set_mandelbrot(frac);
			printf("iteration = %d\n",iteration);
			if (iteration == 100)
				my_mlx_pixel_put(frac, x, y, 0x00FF0000);
			else if (iteration > 50)
				my_mlx_pixel_put(frac, x, y, 0x000000FF);
			else
				my_mlx_pixel_put(frac, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
		mlx_put_image_to_window(frac->mlx, frac->mlx_win, frac->img, 0, 0);
	
}
