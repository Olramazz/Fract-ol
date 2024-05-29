/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:28:06 by olramazz          #+#    #+#             */
/*   Updated: 2024/05/28 01:28:06 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
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
   else if (ft_strncmp(query, "burningship", 12) == 0)
    calculate_burning_ship(fractal);
   else
   {
    ft_putendl_fd("Available fractals: mandelbrot, julia, burningship", 1);
    exit_fractal(fractal);
   }
   fractal->y++;
  }
  fractal->x++;
  fractal->y = 0;
 }
 mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
  0);
 return (0);
}

void put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
 char *pixel;

 pixel = fractal->adress + (y * fractal->line_bytes + x
  * (fractal->pixel_bits / 8));
 *(unsigned int *)pixel = color;
}

void calculate_mandelbrot(t_fractal *fractal)
{
 int  i;
 double x_temp;

 fractal->query = "mandelbrot";
 i = 0;
 fractal->zx = 0.0;
 fractal->zy = 0.0;
 fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
 fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
 while (++i < fractal->max_iter)
 {
  x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
   + fractal->cx;
  fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
  fractal->zx = x_temp;
  if (fractal->zx * fractal->zx + fractal->zy
   * fractal->zy >= __DBL_MAX__)
   break ;
 }
 if (i == fractal->max_iter)
  put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
 else
  put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
    * i));
}

void calculate_julia(t_fractal *fractal, double cx, double cy)
{
 int  i;
 double tmp;

 fractal->query = "julia";
 fractal->cx = cx;
 fractal->cy = cy;
 fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
 fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
 i = 0;
 while (++i < fractal->max_iter)
 {
  tmp = fractal->zx;
  fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
   + fractal->cx;
  fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
  if (fractal->zx * fractal->zx + fractal->zy
   * fractal->zy >= __DBL_MAX__)
   break ;
 }
 if (i == fractal->max_iter)
  put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
 else
  put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i        % 255)));
}

void calculate_burning_ship(t_fractal *fractal)
{
 int  i;
 double x_temp;

 fractal->query = "burningship";
 i = 0;
 fractal->zx = 0.0;
 fractal->zy = 0.0;
 fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
 fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
 while (++i < fractal->max_iter)
 {
  x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
   + fractal->cx;
  fractal->zy = fabs(2.0 * fractal->zx * fractal->zy) + fractal->cy;
  fractal->zx = fabs(x_temp);
  if (fractal->zx * fractal->zx + fractal->zy
   * fractal->zy >= __DBL_MAX__)
   break ;
 }
 if (i == fractal->max_iter)
  put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
 else
  put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
    * i));
}
