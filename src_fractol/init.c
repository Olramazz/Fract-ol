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

void	check_args(int argc, char **argv)
{
	if (argc != 2 && argc != 4)
	{
		write(1, "You are about to discover how reality is built\n", 48);
		error_message("Usage: ./fractol <fractal> <real> <imaginary>\n");
	}
	if (argc < 2 || (ft_strcmp(argv[1], "mandelbrot") != 0
			&& ft_strcmp(argv[1], "julia") != 0
			&& ft_strcmp(argv[1], "burningship") != 0))
	{
		write(1, "You really want to know the secrets of the universe?\n", 54);
		error_message("Available fractals: mandelbrot, julia, burningship\n");
		exit(EXIT_FAILURE);
	}
}

void	init_mlx(t_fractal *fractal)
{
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
}

int	check_init(int argc, char **argv, t_fractal *fractal)
{
	check_args(argc, argv);
	init_mlx(fractal);
	if (init_fractal(argc, argv, fractal) != 0)
		return (1);
	return (0);
}

void	set_fractal_name(int argc, char **argv, t_fractal *fractal)
{
	if (ft_strcmp(fractal->query, "mandelbrot") == 0
		|| ft_strcmp(fractal->query, "burningship") == 0)
	{
		fractal->name = fractal->query;
		fractal->cx = 0;
		fractal->cy = 0;
	}
	else if (ft_strcmp(fractal->query, "julia") == 0)
	{
		if ((argc != 4) || !ft_isfloat(argv[2]) || !ft_isfloat(argv[3]))
		{
			write(1, "Usage: ./fractol julia <real> <imaginary>\n", 42);
			exit_fractal(fractal);
		}
		fractal->name = fractal->query;
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	else
	{
		error_message("Available fractals: mandelbrot, julia, burningship\n");
		exit_fractal(fractal);
		exit(EXIT_FAILURE);
	}
}

int	init_fractal(int argc, char **argv, t_fractal *fractal)
{
	fractal->zoom = 200;
	fractal->offset_x = -2.0;
	fractal->offset_y = -1.5;
	fractal->max_iterations = 1000;
	fractal->color = 0x0066CC;
	fractal->palette_index = 0;
	if (argc >= 2)
		fractal->query = argv[1];
	else
		error_message("Usage: ./fractol <fractal> <real> <imaginary>\n");
	set_fractal_name(argc, argv, fractal);
	return (0);
}
