/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:18:18 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/26 15:29:46 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	closex(t_data *frac)
{
	mlx_destroy_window(frac->mlx, frac->mlx_win);
	exit(0);
}

int	my_key(int keycode, t_data *frac)
{
	if (keycode == 53)
		closex(frac);
	return (0);
}
  
