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

int	draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
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
				ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
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

void	assign_color_to_pixel(t_fractal *fractal, int x, int y, int p_c)
{
	int		bpp;
	int		size_line;
	int		endian;
	int		pixel_pos;
	char	*pixel;

	bpp = fractal->bits_per_pixel / 8;
	size_line = fractal->size_line / bpp;
	endian = fractal->endian;
	pixel_pos = (y * size_line + x) * bpp;
	pixel = fractal->image_data + pixel_pos;
	if (endian == 0)
	{
		pixel[0] = (p_c >> 16) & 0xFF;
		pixel[1] = (p_c >> 8) & 0xFF;
		pixel[2] = p_c & 0xFF;
	}
	else
	{
		pixel[0] = p_c & 0xFF;
		pixel[1] = (p_c >> 8) & 0xFF;
		pixel[2] = (p_c >> 16) & 0xFF;
	}
}

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	const int	*palette;
	int			p_c;

	palette = get_palette(fractal->palette_index);
	p_c = palette[color % PALETTE_SIZE];
	if (x >= 0 && x < SIZE && y >= 0 && y < SIZE)
		assign_color_to_pixel(fractal, x, y, p_c);
}
