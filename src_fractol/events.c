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


int exit_fractal(t_fractal *fractal)
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
    return 0;
}

int key_press(int keycode, t_fractal *fractal)
{
    if (fractal == NULL)
    {
        perror("Error: fractal is NULL\n");
        return (1);
    }

    double move_factor = 2.0;

    if (keycode == 65361) // Left arrow key
        fractal->offset_x -= move_factor / fractal->zoom;
    else if (keycode == 65363) // Right arrow key
        fractal->offset_x += move_factor / fractal->zoom;
    else if (keycode == 65364) // Down arrow key
        fractal->offset_y += move_factor / fractal->zoom;
    else if (keycode == 65362) // Up arrow key
        fractal->offset_y -= move_factor / fractal->zoom;
    else if (keycode == 53) // ESC key
        exit_fractal(fractal);
    else if (keycode == 49)
        change_palette(fractal);

    draw_fractal(fractal, fractal->query, fractal->cx, fractal->cy);
    return (0);
}


int	mouse_press(int button, int x, int y, t_fractal *fractal)
{
    if (fractal == NULL) {
        perror("Error: fractal is NULL\n");
        return (1);
    }

    double zoom_factor = (button == 4) ? 1.1 : 1 / 1.1;
    int steps = 3;
    double step_zoom = pow(zoom_factor, 1.0 / steps);

    for (int i = 0; i < steps; i++)
	{
        double new_offset_x = (x / fractal->zoom) - x / (fractal->zoom * step_zoom);
        double new_offset_y = (y / fractal->zoom) - y / (fractal->zoom * step_zoom);

        if (button == 4 || button == 5)
        {
            fractal->offset_x += new_offset_x;
            fractal->offset_y += new_offset_y;

            fractal->zoom *= step_zoom;
        }
    }

    draw_fractal(fractal, fractal->query, fractal->cx, fractal->cy);

    return (0);
}
