/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:59:25 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/04 21:14:00 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	t_fractal *fractol;
	if (check_args(argc, argv) != 0)
		exit(EXIT_FAILURE);
	fractol = init_fractol(argv);
		if (fractol == NULL)
			exit(EXIT_FAILURE);
	draw_fractal(fractol, fractol->query, fractol->cx, fractol->cy);
	mlx_key_hook(fractol->window, key_press, fractol);
	mlx_mouse_hook(fractol->window, mouse_press, fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
