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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    t_fractal fractal;

    if (check_init(argc, argv, &fractal) != 0)
        return 1;

    draw_fractal(&fractal, fractal.query, fractal.cx, fractal.cy);
    mlx_hook(fractal.window, 17, 0, exit_fractal, &fractal);
    mlx_mouse_hook(fractal.window, mouse_press, &fractal);
    mlx_key_hook(fractal.window, key_press, &fractal);
    mlx_loop(fractal.mlx);
    return 0;
}



