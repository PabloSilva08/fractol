/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:52:13 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/25 15:24:14 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	init_fractol_2(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		if (ft_strlen(argv[1]) != 10)
			help();
		if (argc > 2)
			help();
	}
	if (ft_strncmp(argv[1], "burning", 7) == 0)
	{
		if (ft_strlen(argv[1]) != 7)
			help();
		if (argc > 2)
			help();
	}
}

static	void	init_fractol_1(t_data *frac, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		if (ft_strlen(argv[1]) != 5)
			help();
		if (!argv[2] || !argv[3])
			help_julia();
		frac->julia_x = ft_atof(argv[2]);
		frac->julia_y = ft_atof(argv[3]);
		if (frac->julia_x < -2 || frac->julia_x > 2)
			help_julia();
		if (frac->julia_y < -2 || frac->julia_y > 2)
			help_julia();
	}
	init_fractol_2(argc, argv);
}

static	void	lowername(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		argv[1][i] = ft_tolower(argv[1][i]);
		i++;
	}
}

void	initialization(t_data *frac, int argc, char **argv)
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
	frac->unit_y = (frac->im_max - frac->im_min) / (HEIGHT) ;
	frac->unit_x = (frac->re_max - frac->re_min) / (WIDTH) ;
	frac->zoom = 1;
	frac->top = 0;
	frac->left_x = 0;
	frac->centralize_x = 0;
	frac->centralize_y = 0;
	lowername(argv);
	init_fractol_1(frac, argc, argv);
}

void	creating_screen(t_data *frac)
{
	frac->mlx = mlx_init();
	frac->mlx_win = mlx_new_window(frac->mlx, WIDTH, HEIGHT, "Fract-ol");
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	frac->addr = mlx_get_data_addr(frac->img, &frac->bpp, &frac->line_length,
			&frac->endian);
}
