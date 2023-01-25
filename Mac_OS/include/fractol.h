/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:48:26 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/23 11:49:15 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_opengl/mlx.h"
# include "../../ft_printf/include/ft_printf.h"
# include <math.h> 
# include <sys/errno.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERAC 300

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		iteration;
	double	c_x;
	double	c_y;
	int		pixel_x;
	int		pixel_y;
	double	julia_x;
	double	julia_y;
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
	double	unit_y;
	double	unit_x;
	char	**argv;
}				t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    initialization(t_data *frac, int argc, char **argv);
void    creating_screen(t_data *frac);
void    pre_mandelbrot(t_data *frac);
void    pre_julia(t_data *frac);
void    pre_burning_ship(t_data *frac);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    something_went_wrong(void);
double  ft_atof(char *str);
void    help(void);
void    help_julia(void);
int             closex(t_data *frac);
int             closex2(int keycode, t_data *frac);
#endif
