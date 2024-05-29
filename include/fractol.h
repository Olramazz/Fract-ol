/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:58:21 by olramazz          #+#    #+#             */
/*   Updated: 2024/05/26 21:27:23 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include "libft.h"
#include <stdlib.h>

#define SIZE 500

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char 	*adress;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*query;
	int		max_iter;
	int		color;
	double	zoom;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	int		mouse;

}				t_fractal;

int check_args(int argc, char **argv);
t_fractal *init_fractol(char *query);
int	key_press(int keycode, t_fractal *fractal);
int	mouse_press(int button, int x, int y, t_fractal *fractal);
void calculate_mandelbrot(t_fractal *fractal);
void calculate_julia(t_fractal *fractal, double cx, double cy);
int draw_fractal(t_fractal *fractal, char *query, double cx, double cy);

#endif
