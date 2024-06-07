/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 02:36:00 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/06 02:36:00 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

#include <stdio.h>
#include <math.h>

void calculate_mandelbrot(t_fractal *fractal)
{
 int  i;
 double x_temp;

 fractal->name = "mandel";
 i = 0;
 fractal->zx = 0.0;
 fractal->zy = 0.0;
 fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
 fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
 while (++i < fractal->max_iterations)
 {
  x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
   + fractal->cx;
  fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
  fractal->zx = x_temp;
  if (fractal->zx * fractal->zx + fractal->zy
   * fractal->zy >= __DBL_MAX__)
   break ;
 }
 if (i == fractal->max_iterations)
    put_color_to_pixel(fractal, fractal->x, fractal->y, 0xFCBE11 * (i % 255));
 else
  put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
    * i));
}

void calculate_julia(t_fractal *fractal, double cx, double cy)
{
 int  i;
 double tmp;

 fractal->name = "julia";
 fractal->cx = cx;
 fractal->cy = cy;
 fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
 fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
 i = 0;
 while (++i < fractal->max_iterations)
 {
  tmp = fractal->zx;
  fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
   + fractal->cx;
  fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
  if (fractal->zx * fractal->zx + fractal->zy
   * fractal->zy >= __DBL_MAX__)
   break ;
 }
 if (i == fractal->max_iterations)
    put_color_to_pixel(fractal, fractal->x, fractal->y, 0xFCBE11 * (i % 255));
 else
  put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i
     % 255)));
}

void calculate_burning_ship(t_fractal *fractal)
{
 int  i;
 double x_temp;

 fractal->name = "ship";
 i = 0;
 fractal->zx = 0.0;
 fractal->zy = 0.0;
 fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
 fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
 while (++i < fractal->max_iterations)
 {
  x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
   + fractal->cx;
  fractal->zy = fabs(2.0 * fractal->zx * fractal->zy) + fractal->cy;
  fractal->zx = fabs(x_temp);
  if (fractal->zx * fractal->zx + fractal->zy
   * fractal->zy >= __DBL_MAX__)
   break ;
 }
 if (i == fractal->max_iterations)
    put_color_to_pixel(fractal, fractal->x, fractal->y, 0xFCBE11 * (i % 255));
 else
  put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
    * i));
}
