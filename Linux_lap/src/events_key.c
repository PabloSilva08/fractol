/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:18:18 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/28 00:13:29 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	closex(t_data *frac)
{
	mlx_destroy_window(frac->mlx, frac->mlx_win);
	exit(0);
}

void	choose_fractal(t_data *frac)
{
	mlx_clear_window(frac->mlx, frac->mlx_win);
	if (ft_strncmp(frac->argv[1], "mandelbrot", 10) == 0)
		pre_mandelbrot(frac);
	if (ft_strncmp(frac->argv[1], "julia", 5) == 0)
		pre_julia(frac);
	if (ft_strncmp(frac->argv[1], "burning", 7) == 0)
		pre_burning_ship(frac);
}

void	my_key_2(int keycode, t_data *frac)
{	
	if (keycode == 65361)
	{
		frac->left_x = frac->left_x + 0.1;
		choose_fractal(frac);
	}
	if (keycode == 99)
	{
		if (frac->color_plus > 262144)
			frac->color_plus = 1;
		else
		frac->color_plus = frac->color_plus * 2;
		choose_fractal(frac);
	}
	if (keycode == 112)
	{
		frac->inv = frac->inv * (-1);
		choose_fractal(frac);
	}
}

int	my_key(int keycode, t_data *frac)
{
	if (keycode == 65307)
		closex(frac);
	else if (keycode == 65362)
	{
		frac->top = frac->top - 0.1;
		choose_fractal(frac);
	}
	else if (keycode == 65364)
	{
		frac->top = frac->top + 0.1;
		choose_fractal(frac);
	}
	else if (keycode == 65363)
	{
		frac->left_x = frac->left_x - 0.1;
		choose_fractal(frac);
	}
	else
		my_key_2(keycode, frac);
	return (0);
}
