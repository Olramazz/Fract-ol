/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:45:21 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/05 22:05:55 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_press(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
	{
		end_program(fractal);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
	{
		fractal->zoom *= 1.1;
		fractal->offset_x = (x / fractal->zoom) + fractal->offset_x - (x / (fractal->zoom * 1.1));
		fractal->offset_y = (y / fractal->zoom) + fractal->offset_y - (y / (fractal->zoom * 1.1));
	}
	else if (button == 5)
	{
		fractal->zoom /= 1.1;
		fractal->offset_x = (x / fractal->zoom) + fractal->offset_x - (x / (fractal->zoom * 1.1));
		fractal->offset_y = (y / fractal->zoom) + fractal->offset_y - (y / (fractal->zoom * 1.1));
	}
	draw_fractal(fractal, fractal->query, fractal->cx, fractal->cy);
	return (0);
}

int end_program(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx, fractal->image);
    mlx_destroy_window(fractal->mlx, fractal->window);
    mlx_destroy_display(fractal->mlx);
    free(fractal->mlx);
    free(fractal);
    exit(EXIT_SUCCESS);
    return (0);
}

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int exit_fractal(t_fractal *fractal)
{
	end_program(fractal);
	return(0);
}