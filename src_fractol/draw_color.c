/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 02:37:39 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/06 02:37:39 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

int draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
{
 fractal->x = 0;
 fractal->y = 0;
 while (fractal->x < SIZE)
 {
  while (fractal->y < SIZE)
  {
   if (ft_strncmp(query, "mandelbrot", 10) == 0)
    calculate_mandelbrot(fractal);
   else if (ft_strncmp(query, "julia", 5) == 0)
    calculate_julia(fractal, cx, cy);
   else if (ft_strncmp(query, "burningship", 11) == 0)
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
    int bpp;
    int size_line;
    int endian;

    bpp = fractal->bits_per_pixel / 8;
    size_line = fractal->size_line / bpp;
    endian = fractal->endian;
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE)
    {
        int pixel_pos;
        char *pixel;

        pixel_pos = (y * size_line + x) * bpp;
        pixel = fractal->image_data + pixel_pos;
        if (endian == 0)
        {
            pixel[0] = (color >> 16) & 0xFF; // Red
            pixel[1] = (color >> 8) & 0xFF;  // Green
            pixel[2] = color & 0xFF;         // Blue
        }
        else
        {
            pixel[0] = color & 0xFF;         // Blue
            pixel[1] = (color >> 8) & 0xFF;  // Green
            pixel[2] = (color >> 16) & 0xFF; // Red
        }
    }
}




