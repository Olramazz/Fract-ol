/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:07:49 by olramazz          #+#    #+#             */
/*   Updated: 2024/05/28 02:07:49 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Usage: ./fractol [mandelbrot/julia/burningship ]\n");//cazzo se fare bonus metter piu roba qui
		return (1);
	}
	if (ft_strncmp(argv[1], "mandelbrot") != 0 && ft_strncmp(argv[1], "julia") != 0 && ft_strncmp(argv[1], "burningship") != 0)
	{
		perror("Usage: ./fractol [mandelbrot/julia/burningship ]\n");
		return (1);
	}
	return (0);
}

t_fractal *init_fractol(char *query)
{
	t_fractal *fractol;

	fractol = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractol)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, 500, 500, Fractol);
	fractol->image = mlx_new_image(fractol->mlx, 500, 500);
	fractol->adress = mlx_get_data_addr(fractol->image, &fractol->pixel_bits, &fractol->line_bytes, &fractol->endian);
	fractol->query = query;
	fractol->zoom = 1;
	fractol->max_iter = 50;
	fractol->color = 0;
	fractol->mouse = 0;
	return (fractol);
}

int	key_press(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		fractal->zoom += 0.1;
	return (0);
}
int	mouse_press(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
		fractal->zoom += 0.1;
	return (0);
}

