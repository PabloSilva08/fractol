/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:52:13 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/24 00:18:24 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	init_fractol(t_data *frac, char **argv)
{
//	int flag;

//	flag = 0;
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
//		flag = 1;
		frac->julia_x = ft_atof(argv[2]);
		frac->julia_y = ft_atof(argv[3]);
		if (frac->julia_x < -2 || frac->julia_x > 2)
			help_julia();
		if (frac->julia_y < -2 || frac->julia_y > 2)
			help_julia();
	}
}

void	initialization(t_data *frac, char **argv)
{
	int	i;

	i = 0;
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
	while(argv[1][i] != '\0')
	{
		argv[1][i] = ft_tolower(argv[1][i]);
		i++;
	}
	init_fractol(frac, argv);
}

void	creating_screen(t_data *frac)
{
	frac->mlx = mlx_init();
	frac->mlx_win = mlx_new_window(frac->mlx, WIDTH, HEIGHT, "Fract-ol");
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	frac->addr = mlx_get_data_addr(frac->img, &frac->bpp, &frac->line_length,
			&frac->endian);
}
