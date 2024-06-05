/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:07:49 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/05 21:00:32 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		perror("Usage: ./fractol [mandelbrot/julia][<real_part> <imaginary_part> for julia]\n");
		return (1);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1], "julia") != 0)
	{
		perror("Usage: ./fractol [mandelbrot/julia] [<real_part> <imaginary_part> for julia]\n");
		return (1);
	}
	if (ft_strcmp(argv[1], "julia") == 0 && argc != 4)
	{
		perror("Usage: ./fractol julia <real_part> <imaginary_part>\n");
		return (1);
	}
	return (0);
}

t_fractal	*init_fractol(char **argv)
{
	t_fractal	*fractol;
	t_color color_palette[PALETTE_SIZE] = {
        {148, 0, 211},
        {75, 0, 130},
        {0, 0, 255},
        {0, 255, 0},
        {255, 255, 0},
        {255, 127, 0},
        {255, 0, 0},
        {255, 20, 147},
        {255, 105, 180},
        {255, 255, 255}
    };
	fractol = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractol)
		ft_error("Error: malloc failed\n");
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		ft_error("Error: mlx_init failed\n");
	fractol->window = mlx_new_window(fractol->mlx, SIZE, SIZE, "Fractol");
	if (fractol->window == NULL)
		ft_error("Error: mlx_new_window failed\n");
	fractol->image = mlx_new_image(fractol->mlx, SIZE, SIZE);
	if (fractol->image == NULL)
		ft_error("Error: mlx_new_image failed\n");
	fractol->adress = mlx_get_data_addr(fractol->image, &fractol->pixel_bits, &fractol->line_bytes, &fractol->endian);
	fractol->zoom = 1.0;
	fractol->offset_x = -2.0;
	fractol->offset_y = -1.5;
	fractol->query = argv[1];
	fractol->max_iter = MAX_ITER;
    ft_memcpy(fractol->color_palette, color_palette, sizeof(color_palette));
	if(ft_strncmp(fractol->query, "julia", 5) == 0)
	{
		fractol->cx = ft_atof(argv[2]);
		fractol->cy= ft_atof(argv[3]);
	}
	return (fractol);
}


