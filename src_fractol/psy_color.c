/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psy_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:47:17 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/08 01:47:17 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

static int psychedelic_palette[] = {
    0xFF00FF, 0x00FFFF, 0xFFFF00, 0xFF0000, 0x00FF00, 0x0000FF, 0xFF8000, 0x8000FF,
    0x80FF00, 0x0080FF, 0xFF0080, 0x800080, 0x808000, 0x008080, 0x808080, 0xFFFFFF
};

int get_psychedelic_color(int iteration, int max_iterations)
{
    double t = (double)iteration / (double)max_iterations;
    int color_index = (int)(t * (sizeof(psychedelic_palette) / sizeof(psychedelic_palette[0])));
    return psychedelic_palette[color_index % (sizeof(psychedelic_palette) / sizeof(psychedelic_palette[0]))];
}

