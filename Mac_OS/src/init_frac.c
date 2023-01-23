/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:52:13 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/23 15:01:34 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialization(t_data *frac, char **argv)
{
	frac->mlx = NULL;
	frac->mlx_win = NULL;
	frac->img = NULL;
	frac->addr = NULL;
	frac->iteration = 0;
	frac->c_x = 0;
	frac->c_y = 0;
	frac->pixel_x = 0;
	frac->pixel_y = 0;
	frac->re_min = -2.0;
	frac->re_max = 2.0;
	frac->im_min = -2.0;
	frac->im_max = frac->im_min + (frac->re_max - frac->re_min) * HEIGHT
		/ WIDTH;
	frac->unit_y = (frac->im_max - frac->im_min) / (HEIGHT - 1);
	frac->unit_x = (frac->re_max - frac->re_min) / (WIDTH - 1);
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		frac->julia_x = ft_atof(argv[2]);
		frac->julia_y = ft_atof(argv[3]);
	}
}

void	creating_screen(t_data *frac)
{
	frac->mlx = mlx_init();
	frac->mlx_win = mlx_new_window(frac->mlx, WIDTH, HEIGHT, "Fract-ol");
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	frac->addr = mlx_get_data_addr(frac->img, &frac->bpp, &frac->line_length,
			&frac->endian);
}
