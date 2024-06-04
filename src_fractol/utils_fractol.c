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
	if (argc < 2)
	{
		perror("Usage: ./fractol [mandelbrot/julia/burningship] [<real_part> <imaginary_part> for julia]\n");
		return (1);
	}

	if (strcmp(argv[1], "mandelbrot") != 0 && strcmp(argv[1], "julia") != 0 && strcmp(argv[1], "burningship") != 0)
	{
		perror("Usage: ./fractol [mandelbrot/julia/burningship] [<real_part> <imaginary_part> for julia]\n");
		return (1);
	}

	if (strcmp(argv[1], "julia") == 0 && argc != 4)
	{
		perror(stderr, "Usage: ./fractol julia <real_part> <imaginary_part>\n");
		return (1);
	}
	return (0);
}

t_fractal *init_fractol(char **argv)
{
	t_fractal *fractol;

	fractol = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractol)
		ft_error("Error: malloc failed\n");
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		ft_error("Error: mlx_init failed\n");
	fractol->window = mlx_new_window(fractol->mlx, 500, 500, "Fractol");
	if (fractol->window == NULL)
		ft_error("Error: mlx_new_window failed\n");
	fractol->image = mlx_new_image(fractol->mlx, 500, 500);
	if (fractol->image == NULL)
		ft_error("Error: mlx_new_image failed\n");
	fractol->adress = mlx_get_data_addr(fractol->image, &fractol->pixel_bits, &fractol->line_bytes, &fractol->endian);
	fractol->zoom = 1.0;
	fractol->offset_x = -2.0;
	fractol->offset_y = -1.5;
	fractol->query = argv[1];
	if(ft_strncmp(fractol->query, "julia", 5) == 0)
	{
		fractol->cx = atof(argv[2]);
		fractol->cy= atof(argv[3]);
	}

	return (fractol);
}

int	key_press(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
		exit(0);
}

int	mouse_press(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
	{
		fractal->zoom *= 1.1;
		fractal->offset_x = (x / fractal->zoom) + fractal->offset_x - (x / (fractal->zoom * 1.1));
		fractal->offset_y = (y / fractal->zoom) + fractal->offset_y - (y / (fractal->zoom * 1.1));
	}
	else if(button == 5)
	{
		fractal->zoom /= 1.1;
		fractal->offset_x = (x / fractal->zoom) + fractal->offset_x - (x / (fractal->zoom * 1.1));
		fractal->offset_y = (y / fractal->zoom) + fractal->offset_y - (y / (fractal->zoom * 1.1));
	}
	draw_fractal(fractal, fractal->query, fractal->cx, fractal->cy);
	return (0);
}

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

t_color switch_color(t_color start, t_color end, double ratio)
{
	t_color result;

	result.r = (unsigned char)((1-ratio) * start.r + ratio * end.r);
	result.g = (unsigned char)((1-ratio) * start.g + ratio * end.g);
	result.b = (unsigned char)((1-ratio) * start.b + ratio * end.b);

	return (result);
}
