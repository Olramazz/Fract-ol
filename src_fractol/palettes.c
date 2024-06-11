/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:25:55 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/11 17:25:55 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractals.h"

static const int	*init_palette1(void)
{
	static const int	palette[PALETTE_SIZE] = {
		0xFF33CC, 0x33FFCC, 0xCC33FF, 0x33CCFF,
		0xCCFF33, 0xFFCC33, 0x00FF00, 0xFF00FF,
		0x00FFFF, 0xFFFF00, 0xFF0033, 0x33FF00,
		0x0033FF, 0x3300FF, 0xFF3300, 0x00FF33
	};

	return (palette);
}

static const int	*init_palette2(void)
{
	static const int	palette[PALETTE_SIZE] = {
		0x6600CC, 0xCC0066, 0x00CC66, 0x66CC00,
		0x0066CC, 0xCC6600, 0x00CCFF, 0xFF00CC,
		0xCCFF00, 0x00FFCC, 0xCC00FF, 0xFFCC00,
		0x00CCCC, 0xCCCC00, 0xCC00CC, 0x00CC00
	};

	return (palette);
}

static const int	*init_palette3(void)
{
	static const int	palette[PALETTE_SIZE] = {
		0x9900FF, 0x00FF99, 0xFF9900, 0x00FF33,
		0x33FF00, 0x0033FF, 0xFF3300, 0x00FFCC,
		0xCCFF00, 0xFF00CC, 0x00CCFF, 0xFFCC00,
		0x00CCCC, 0xCCCC00, 0xCC00CC, 0x00CC00
	};

	return (palette);
}

const int	*get_palette(int index)
{
	if (index == 0)
		return (init_palette1());
	else if (index == 1)
		return (init_palette2());
	else
		return (init_palette3());
}
