/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 07:45:57 by pvieira-          #+#    #+#             */
/*   Updated: 2023/01/24 15:29:48 by pvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help(void)
{
	ft_putstr_fd("\e[36;1m========================================\e[0m", 1);
	ft_putstr_fd("\e[36;1m========================================\e[0m\n", 1);
	ft_putstr_fd("\e[34;1m To access the mandelbrot fractal,\e[0m", 1);
	ft_putstr_fd("\e[34;1m use mandelbroat as a parameter.\e[0m\n", 1);
	ft_putstr_fd("\e[35;1mExample\n\e[0m", 1);
	ft_putstr_fd("\e[32;1m $ ./fractol mandelbrot\e[0m\n", 1);
	ft_putstr_fd("\e[34;1m To access the burning ship fractal,\e[0m", 1);
	ft_putstr_fd("\e[34;1m use burning as a parameter.\e[0m\n", 1);
	ft_putstr_fd("\e[35;1mExample\n\e[0m", 1);
	ft_putstr_fd("\e[32;1m $ ./fractol burning\e[0m\e[0m\n", 1);
	ft_putstr_fd("\e[34;1m To access the Julia fractal,\e[0m", 1);
	ft_putstr_fd("\e[34;1m use julia as the first parameter,\e[0m\n", 1);
	ft_putstr_fd("\e[34;1m then use two values between -2.0 and 2.0\e[0m", 1);
	ft_putstr_fd("\e[34;1m to represent the real\e[0m\n", 1);
	ft_putstr_fd("\e[34;1m and imaginary parts.\e[0m\n", 1);
	ft_putstr_fd("\e[35;1mExample\n\e[0m", 1);
	ft_putstr_fd("\e[32;1m $ ./fractol julia -0.4 0.6\e[0m", 1);
	ft_putstr_fd("\e[34;1m \nor\e[0m\n", 1);
	ft_putstr_fd("\e[32;1m $ ./fractol julia -0.835 -0.2321\e[0m\n", 1);
	ft_putstr_fd("\e[36;1m----------------------------------------\e[0m", 1);
	ft_putstr_fd("\e[36;1m----------------------------------------\e[0m\n", 1);
	ft_putstr_fd("\e[90;1m * press \"c\" to change color.\e[0m\n", 1);
	ft_putstr_fd("\e[90;1m * press \"p\" to invert the complex axi.\e[0m\n", 1);
	ft_putstr_fd("\e[90;1m * use the arrows to move with the imagi.\e[0m\n", 1);
	ft_putstr_fd("\e[36;1m========================================\e[0m", 1);
	ft_putstr_fd("\e[36;1m========================================\e[0m\n", 1);
	exit(0);
}

void	help_julia(void)
{
	ft_putstr_fd("\e[31;5m========================================\e[0m", 1);
	ft_putstr_fd("\e[31;5m========================================\e[0m\n", 1);
	ft_putstr_fd("\e[31;1m Please enter values between -2 and 2\e[0m", 1);
	ft_putstr_fd("\e[31;1m for real and imaginary parts\e[0m\n", 1);
	ft_putstr_fd("\e[31;5m========================================\e[0m", 1);
	ft_putstr_fd("\e[31;5m========================================\e[0m\n", 1);
	exit(1);
}
