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

#include "../include/fractals.h"

int	exit_fractal(t_fractal *fractal)
{
	if (fractal->image)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (fractal->window)
		mlx_destroy_window(fractal->mlx, fractal->window);
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit(0);
	return (0);
}

int	error_message(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
	return (1);
}

int	key_press(int keycode, t_fractal *fractal)
{
	double	move_factor;

	if (fractal == NULL)
		error_message("Error: fractal is NULL\n");
	move_factor = 2.0;
	if (keycode == 65361)
		fractal->offset_x -= move_factor / fractal->zoom;
	else if (keycode == 65363)
		fractal->offset_x += move_factor / fractal->zoom;
	else if (keycode == 65364)
		fractal->offset_y += move_factor / fractal->zoom;
	else if (keycode == 65362)
		fractal->offset_y -= move_factor / fractal->zoom;
	else if (keycode == 49)
		fractal->palette_index = 0;
	else if (keycode == 50)
		fractal->palette_index = 1;
	else if (keycode == 51)
		fractal->palette_index = 2;
	else if (keycode == 65307)
		exit_fractal(fractal);
	draw_fractal(fractal, fractal->query, fractal->cx, fractal->cy);
	return (0);
}

void	handle_zoom_and_offset(int button, int x, int y, t_fractal *fractal)
{
	double	zoom_factor;
	double	step_zoom;
	double	new_offset_x;
	double	new_offset_y;

	zoom_factor = 1.1;
	if (button != 4)
		zoom_factor = 1 / zoom_factor;
	step_zoom = pow(zoom_factor, 1.0 / 3);
	new_offset_x = (x / fractal->zoom) - x / (fractal->zoom * step_zoom);
	new_offset_y = (y / fractal->zoom) - y / (fractal->zoom * step_zoom);
	fractal->offset_x += new_offset_x;
	fractal->offset_y += new_offset_y;
	fractal->zoom *= step_zoom;
	fractal->offset_x += (x / fractal->zoom) - x / (fractal->zoom * step_zoom);
	fractal->offset_y += (y / fractal->zoom) - y / (fractal->zoom * step_zoom);
	fractal->zoom *= step_zoom;
	fractal->offset_x += (x / fractal->zoom) - x / (fractal->zoom * step_zoom);
	fractal->offset_y += (y / fractal->zoom) - y / (fractal->zoom * step_zoom);
	fractal->zoom *= step_zoom;
}

int	mouse_press(int button, int x, int y, t_fractal *fractal)
{
	if (fractal == NULL)
		error_message("Error: fractal is NULL\n");
	if (button == 4 || button == 5)
		handle_zoom_and_offset(button, x, y, fractal);
	draw_fractal(fractal, fractal->query, fractal->cx, fractal->cy);
	return (0);
}
