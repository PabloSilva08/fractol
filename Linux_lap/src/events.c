/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:14:12 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/24 22:59:12 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	closex(t_data *frac)
{
	mlx_destroy_window(frac->mlx, frac->mlx_win);
	exit(0);
}

/*
int	closex2(int keycode)
{
	printf("key = %d\n", keycode);
	return(0);
}
*/

int	closex2(int keycode, t_data *frac)
{
	if (keycode == 53)
	{
		mlx_destroy_window(frac->mlx, frac->mlx_win);
		exit (0);
	}
	return(0);
}
