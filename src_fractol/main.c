/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 02:36:39 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/06 02:36:39 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

int main(int argc, char **argv)
{
    t_fractal   fractal;
    char        *query;

    if (argc != 2)
    {
        perror("Usage: ./fractal <fractal_type>\n");
        return (1);
    }
    query = argv[1];
    fractal.mlx = mlx_init();
    fractal.window = mlx_new_window(fractal.mlx, SIZE, SIZE, "Fractal");
    fractal.image = mlx_new_image(fractal.mlx, SIZE, SIZE);
    fractal.image_data = mlx_get_data_addr(fractal.image, &fractal.bits_per_pixel, &fractal.size_line, &fractal.endian);
    fractal.zoom = 200;
    fractal.offset_x = -2.0;
    fractal.offset_y = -1.5;
    fractal.max_iterations = 1000;
    fractal.color = 0x0066CC;
    draw_fractal(&fractal, query, 0, 0);
    mlx_hook(fractal.window, 2, 0, exit_fractal, &fractal);
    mlx_mouse_hook(fractal.window, mouse_press, &fractal);
    mlx_key_hook(fractal.window, key_press, &fractal);
    mlx_loop(fractal.mlx);
    return (0);
}

