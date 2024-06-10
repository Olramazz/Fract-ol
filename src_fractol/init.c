/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:07:48 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/08 15:07:48 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

int	check_init(int argc, char **argv, t_fractal *fractal)
{
	if (argc != 2 && argc != 4)
	{
		perror("Usage: ./fractol [mandelbrot/julia/burningship]\n");
		perror("Usage: ./fractol julia <real_part> <imaginary_part>\n");
		return (1);
	}
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
	{
		perror("Error: mlx_init failed\n");
		return (1);
	}
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fractal");
	if (!fractal->window)
	{
		perror("Error: mlx_new_window failed\n");
		return (1);
	}
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (!fractal->image)
	{
		perror("Error: mlx_new_image failed\n");
		return (1);
	}
	fractal->image_data = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
	if (!fractal->image_data)
	{
		perror("Error: mlx_get_data_addr failed\n");
		return (1);
	}
	init_fractal(argc, argv, fractal);
	if (init_fractal(argc, argv, fractal) != 0)
		return (1);
	return (0);
}

int	init_fractal(int argc, char **argv, t_fractal *fractal)
{
	fractal->zoom = 200;
	fractal->offset_x = -2.0;
	fractal->offset_y = -1.5;
	fractal->max_iterations = 1000;
	fractal->color = 0x0066CC;
	fractal->palette = 0;
	fractal->query = argv[1];
	if (ft_strcmp(fractal->query, "mandelbrot") == 0
		|| ft_strcmp(fractal->query, "burningship") == 0)
	{
		fractal->name = fractal->query;
		fractal->cx = 0;
		fractal->cy = 0;
	}
	else if (ft_strcmp(fractal->query, "julia") == 0)
	{
		if (argc != 4)
		{
			perror("Usage: ./fractol julia <real_part> <imaginary_part>\n");
			return (1);
		}
		fractal->name = fractal->query;
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	else
	{
		perror("Available fractals: mandelbrot, julia, burningship\n");
		return (1);
	}
	return (0);
}

