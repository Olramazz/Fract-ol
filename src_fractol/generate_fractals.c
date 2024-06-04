/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_fractals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:28:06 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/04 21:13:52 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			if (ft_strncmp(query, "mandelbrot", 11) == 0)
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

void	put_color_to_pixel(t_fractal *fractal, int x, int y, t_color color)
{
	char	*pixel;

	pixel = fractal->adress + (y * fractal->line_bytes + x
			* (fractal->pixel_bits / 8));
	*(unsigned int *)pixel = (color.r << 16) + (color.g << 8) + color.b;
}

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_temp;
	double	t;
	t_color	color;
	t_color	start_color;
	t_color	end_color;

	fractal->query = "mandelbrot";
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iter)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = 2.0 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
	}
	if (i == fractal->max_iter)
		color = (t_color){0, 0, 0};
	else
    {
        t = (double)i / fractal->max_iter;
        int idx = (int)(t * (PALETTE_SIZE - 1));
        start_color = fractal->color_palette[idx];
        end_color = fractal->color_palette[(idx + 1) % PALETTE_SIZE];
        t = (t * (PALETTE_SIZE - 1)) - idx;
        color = interpolate_color(start_color, end_color, t);
    }
    put_color_to_pixel(fractal, fractal->x, fractal->y, color);
}
void calculate_julia(t_fractal *fractal, double cx, double cy)
{
    int i;
    double tmp;
    double t;
    t_color color;
    t_color start_color, end_color;

    fractal->query = "julia";
    fractal->cx = cx;
    fractal->cy = cy;
    fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
    fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;

    i = 0;
    while (++i < fractal->max_iter) {
        tmp = fractal->zx;
        fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
        fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
        if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
            break;
    }

    if (i == fractal->max_iter)
	{
        color = (t_color){0, 0, 0};
    }
	else
	{
        t = (double)i / fractal->max_iter;
        int idx = (int)(t * (PALETTE_SIZE - 1));
        start_color = fractal->color_palette[idx];
        end_color = fractal->color_palette[(idx + 1) % PALETTE_SIZE];
        t = (t * (PALETTE_SIZE - 1)) - idx;
        color = interpolate_color(start_color, end_color, t);
    }
    put_color_to_pixel(fractal, fractal->x, fractal->y, color);	
}
