/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:40:52 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/05 22:25:01 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
