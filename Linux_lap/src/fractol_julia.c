/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:50:08 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/22 23:41:21 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	set_julia(t_data *frac)
{
	double	x;
	double	y;
	double	next_x;
	double	next_y;

	x = frac->c_x;
	y = frac->c_y;
	frac->iteration = 0;
	while (x * x + y * y <= 4 && frac->iteration < MAX_ITERAC)
	{
		next_x = x * x - y * y + frac->julia_x;
		next_y = 2 * x * y + frac->julia_y;
		x = next_x;
		y = next_y;
		frac->iteration++;
	}
}

void	pre_julia(t_data *frac)
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
			set_julia(frac);
			if (frac->iteration == 300)
				my_mlx_pixel_put(frac, x, y, 0x00000000);
			else if (frac->iteration > 250)
				my_mlx_pixel_put(frac, x, y, 0x00FFFF00);
			else if (frac->iteration > 100)
				my_mlx_pixel_put(frac, x, y, 0x00FF0000);
			else
				my_mlx_pixel_put(frac, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frac->mlx, frac->mlx_win, frac->img, 0, 0);
}

double ft_atof(char *str)
{
	size_t	i;
	double	sign;
	double	result;
	double	tenth;

	i = 0;
	sign = 1.0;
	result = 0;
	tenth = 0.1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = (str[i] - '0') + (result * 10.0);
		i++;
	}
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result + ((str[i] - '0') * tenth);
		tenth = tenth * 0.1;
		i++;
	}
	if (str[i] != '\0')
	{
		errno = 22;
		perror("error");
		exit(errno);
	}
	return (result * sign);
}
