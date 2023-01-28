/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:02:15 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/27 23:33:00 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

int	main(int argc, char **argv)
{
	t_data	frac;

	if (argc < 2 || argc > 4)
		help();
	initialization(&frac, argc, argv);
	creating_screen(&frac);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		pre_mandelbrot(&frac);
	if (ft_strncmp(argv[1], "julia", 5) == 0)
		pre_julia(&frac);
	if (ft_strncmp(argv[1], "burning", 7) == 0)
		pre_burning_ship(&frac);
	mlx_mouse_hook(frac.mlx_win, my_mouse, &frac);
	mlx_key_hook(frac.mlx_win, my_key, &frac);
	mlx_hook(frac.mlx_win, 17, 0, closex, &frac);
	mlx_loop(frac.mlx);
	return (0);
}
