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
		error_message("Usage: ./fractol <fractal> <real_part> <imaginary_part>\n");
	if(argc < 2 || (ft_strcmp(argv[1], "mandelbrot") != 0
		&& ft_strcmp(argv[1], "julia") != 0
		&& ft_strcmp(argv[1], "burningship") != 0))
		{
			error_message("Available fractals: mandelbrot, julia, burningship\n");
			exit(EXIT_FAILURE);
		}
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		error_message("Error: mlx_init failed\n");
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fractal");
	if (!fractal->window)
		error_message("Error: mlx_new_window failed\n");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (!fractal->image)
		error_message("Error: mlx_new_image failed\n");
	fractal->image_data = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
	if (!fractal->image_data)
		error_message("Error: mlx_get_data_addr failed\n");
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
	fractal->palette_index = 0;
	if(argc >= 2)
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
			error_message("Usage: for julia <real_part> <imaginary_part>\n");
		fractal->name = fractal->query;
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	else
		error_message("Available fractals: mandelbrot, julia, burningship\n");
	return (0);
}
