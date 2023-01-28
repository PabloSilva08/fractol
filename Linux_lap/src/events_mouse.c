/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:14:12 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/26 15:39:28 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	zoom_plus(int x, int y, t_data *frac)
{	
	double	old_center_x;
	double	center_x;
	double	old_center_y;
	double	center_y;

	old_center_x = -2.0 + x * frac->unit_x * frac->zoom;
	old_center_y = -2.0 + y * frac->unit_y * frac->zoom;
	frac->zoom = frac->zoom * 0.9;
	center_x = -2.0 + x * frac->unit_x * frac->zoom;
	center_y = -2.0 + y * frac->unit_y * frac->zoom;
	frac->centralize_x += -center_x + old_center_x;
	frac->centralize_y += -center_y + old_center_y;
}

static	void	zoom_less(int x, int y, t_data *frac)
{	
	double	old_center_x;
	double	center_x;
	double	old_center_y;
	double	center_y;

	old_center_x = -2.0 + x * frac->unit_x * frac->zoom;
	old_center_y = -2.0 + y * frac->unit_y * frac->zoom;
	frac->zoom = frac->zoom * 1.1;
	center_x = -2.0 + x * frac->unit_x * frac->zoom;
	center_y = -2.0 + y * frac->unit_y * frac->zoom;
	frac->centralize_x += -center_x + old_center_x;
	frac->centralize_y += -center_y + old_center_y;
}

int	my_mouse(int keycode, int x, int y, t_data *frac)
{
	if (keycode == 5)
	{
		zoom_plus(x, y, frac);
		mlx_clear_window(frac->mlx, frac->mlx_win);
		if (ft_strncmp(frac->argv[1], "mandelbrot", 10) == 0)
			pre_mandelbrot(frac);
		if (ft_strncmp(frac->argv[1], "julia", 5) == 0)
			pre_julia(frac);
		if (ft_strncmp(frac->argv[1], "burning", 7) == 0)
			pre_burning_ship(frac);
	}
	if (keycode == 4)
	{
		zoom_less(x, y, frac);
		mlx_clear_window(frac->mlx, frac->mlx_win);
		if (ft_strncmp(frac->argv[1], "mandelbrot", 10) == 0)
			pre_mandelbrot(frac);
		if (ft_strncmp(frac->argv[1], "julia", 5) == 0)
			pre_julia(frac);
		if (ft_strncmp(frac->argv[1], "burning", 7) == 0)
			pre_burning_ship(frac);
	}
	return (0);
}
