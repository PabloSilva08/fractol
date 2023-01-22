/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:02:15 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/21 18:09:47 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
		
void	initialization(t_data *frac, char **argv)
{
	frac->mlx = NULL;
	frac->mlx_win = NULL;
	frac->img = NULL;
	frac->addr = NULL;
//	frac->iteration = 0;
	frac->c_x = 0;
	frac->c_y = 0;
	frac->pixel_x = 0;
	frac->pixel_y = 0;
	frac->re_min = -2.0;
    frac->re_max = 2.0;
	frac->im_min = -2.0;
	frac->im_max = frac->im_min + (frac->re_max-frac->re_min)*HEIGHT/WIDTH;
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

int	main(int argc, char **argv)
{
	t_data	frac;

	if (argc < 2)
		help();
	initialization(&frac, argv);
	creating_screen(&frac);
	pixel_coordinate_conversio(&frac);






	//-----------------
	//
//	paiting(&frac, 0x00FF0000);
	//--------------
//	mlx_mouse_hook(frac.mlx_win, keys, &frac);


  //  mlx_hook(frac.mlx_win, 2, 0, closex2, &frac);	
   // mlx_hook(frac.mlx_win, 17, 0, closex, &frac); //	
//	mlx_put_image_to_window(frac.mlx, frac.mlx_win, frac.img, 0, 0);
	mlx_loop(frac.mlx);
	return (0);
}
