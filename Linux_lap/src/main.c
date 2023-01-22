/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:02:15 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/22 17:23:13 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

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
	frac->julia_x = 0.31446;
	frac->julia_y = -0.05;
	frac->re_min = -2.0;
	frac->re_max = 2.0;
	frac->im_min = -2.0;
	frac->im_max = frac->im_min + (frac->re_max - frac->re_min) * HEIGHT
		/ WIDTH;
	frac->argv = argv;
	frac->unit_y = (frac->im_max - frac->im_min) / (HEIGHT - 1);
	frac->unit_x = (frac->re_max - frac->re_min) / (WIDTH - 1);
}

void	creating_screen(t_data *frac)
{
	frac->mlx = mlx_init();
	frac->mlx_win = mlx_new_window(frac->mlx, WIDTH, HEIGHT, "Fract-ol");
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	frac->addr = mlx_get_data_addr(frac->img, &frac->bpp, &frac->line_length,
			&frac->endian);
}

int	closex(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	frac;

	if (argc < 2)
		help();
	initialization(&frac, argv);
	creating_screen(&frac);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		pre_mandelbrot(&frac);
	if (ft_strncmp(argv[1], "julia", 5) == 0)
		pre_julia(&frac);
//	mlx_mouse_hook(frac.mlx_win, keys, &frac);
//  mlx_hook(frac.mlx_win, 2, 0, closex2, &frac);	
	mlx_hook(frac.mlx_win, 17, 0, closex, &frac);
	mlx_loop(frac.mlx);
	return (0);
}
