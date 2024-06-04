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
#define MAX_ITER 100
#define PALETTE_SIZE 10

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

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
	double	zoom;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
}				t_fractal;

int check_args(int argc, char **argv);
t_fractal *init_fractol(char **argv);
int	key_press(int keycode, t_fractal *fractal);
int	mouse_press(int button, int x, int y, t_fractal *fractal);
void calculate_mandelbrot(t_fractal *fractal);
void calculate_julia(t_fractal *fractal, double cx, double cy);
int draw_fractal(t_fractal *fractal, char *query, double cx, double cy);
void put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
void ft_error(char *str);
t_color switch_color(t_color start, t_color end, double ratio);

#endif
