/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:28:06 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/05 21:27:28 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
{
    fractal->x = 0;
    fractal->y = 0;
    while (fractal->x < SIZE)
    {
        while (fractal->y < SIZE)
        {
            if (ft_strncmp(query, "mandelbrot", 7) == 0)
                calculate_mandelbrot(fractal);
            else if (ft_strncmp(query, "julia", 6) == 0)
                calculate_julia(fractal, cx, cy);
            else
            {
                ft_putendl_fd("Available fractals: mandelbrot, julia", 1);
                exit_fractal(fractal);
            }
            fractal->y++;
        }
        fractal->x++;
        fractal->y = 0;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
    return (0);
}

void put_color_to_pixel(t_fractal *fractal, int x, int y, t_color color)
{
    int color_value = (color.r << 16) + (color.g << 8) + color.b;
    char *pixel = fractal->adress + (y * fractal->line_bytes + x * (fractal->pixel_bits / 8));
    *(unsigned int *)pixel = color_value;
}

t_color interpolate_color(t_color start, t_color end, double ratio)
{
    t_color result;
    result.r = (unsigned char)((1 - ratio) * start.r + ratio * end.r);
    result.g = (unsigned char)((1 - ratio) * start.g + ratio * end.g);
    result.b = (unsigned char)((1 - ratio) * start.b + ratio * end.b);
    return result;
}
