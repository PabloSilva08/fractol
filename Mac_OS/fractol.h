#ifndef FRACTOL_H
# define FRACTOL_H

#include "./minilibx_opengl/mlx.h"
#include <unistd.h>

typedef struct	s_data 
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		standard_width;
	int		standard_height;
	int		initial_x;
	int		initial_y;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_screen(t_data *frac);
void	paiting(t_data *frac, int color);
int		keys(int keynote, int x, int y, t_data *frac);
//void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
//int     mlx_clear_window(void *mlx_ptr, void *win_ptr);
//int     mlx_destroy_window(void *mlx_ptr, void *win_ptr);
//int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
//int		mlx_loop(void *mlx_ptr);
#endif
