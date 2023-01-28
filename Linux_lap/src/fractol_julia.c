/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:50:08 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/26 12:49:42 by pvieira-         ###   ########.fr       */
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
		frac->c_y = frac->inv * (frac->im_max - frac->centralize_y + frac->top
				- (y * frac->unit_y * frac->zoom));
		while (x < WIDTH)
		{
			frac->c_x = frac->re_min + frac->left_x + frac->centralize_x
				+ (x * frac->unit_x * frac->zoom);
			set_julia(frac);
			if (frac->iteration == MAX_ITERAC)
				my_mlx_pixel_put(frac, x, y, 0x0000000);
			else
				my_mlx_pixel_put(frac, x, y, frac->iteration * 0x00F0F8FF* frac->color_plus);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frac->mlx, frac->mlx_win, frac->img, 0, 0);
}

static	double	ft_atof2(char *str, size_t i, double result)
{
	double	tenth;

	tenth = 0.1;
	while (ft_isdigit(str[i]))
	{
		result = result + ((str[i] - '0') * tenth);
		tenth = tenth * 0.1;
		i++;
	}
	if (str[i] != '\0')
	{
		errno = 22;
		something_went_wrong();
	}
	return (result);
}

double	ft_atof(char *str)
{
	size_t	i;
	double	sign;
	double	result;

	i = 0;
	sign = 1.0;
	result = 0;
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
	result = ft_atof2(str, i, result);
	return (result * sign);
}
