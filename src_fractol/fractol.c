/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:59:25 by olramazz          #+#    #+#             */
/*   Updated: 2024/05/26 21:27:20 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	t_fractal *fractal;
	if (check_args(argc, argv) != 0)
		exit(EXIT_FAILURE);
	fractal = init_fractol(argv);
		if (fractal == NULL)
			return (0);
	int draw_fractal(fractal, argv[1], 0.0, 0.0)
	mlx_key_hook(fractal.window, key_press, fractal);
	mlx_mouse_hook(fractal.window, mouse_press, fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
