/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:36:32 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/21 17:10:43 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

//void	paiting(t_data *frac, int iteraction)
//{
//	if (iteraction == MAX_ITERAC)
//		my_mlx_pixel_put(frac, x, y, 0x00FF0000);
//	else
//		my_mlx_pixel_put(frac, x, y, 0x00FFFFFF);
//}
