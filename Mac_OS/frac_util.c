#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_screen(t_data *frac)
{
	frac->img = mlx_new_image(frac->mlx, frac->standard_width,frac->standard_height);
	frac->addr = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->line_length,
				&frac->endian);
}
