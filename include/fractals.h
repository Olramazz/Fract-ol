/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:58:21 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/05 21:00:39 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <float.h>
# include <unistd.h>

# define SIZE 900
#define PALETTE_SIZE 16

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*image_data;
	char	*query;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iterations;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		color;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	char	*name;
	int palette_index;
}			t_fractal;

int			check_init(int argc, char **argv, t_fractal *fractal);
void		check_args(int argc, char **argv);
void		init_mlx(t_fractal *fractal);
int			init_fractal(int argc, char ** argv, t_fractal *fractal);
void		set_fractal_name(int argc, char **argv, t_fractal *fractal);
int			draw_fractal(t_fractal *fractal, char *query, double cx, double cy);
void		calculate_mandelbrot(t_fractal *fractal);
void		calculate_julia(t_fractal *fractal, double cx, double cy);
void		calculate_burning_ship(t_fractal *fractal);
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
void		assign_color_to_pixel(t_fractal *fractal, int x, int y, int palette_color);
const int	*get_palette(int index);
int			key_press(int keycode, t_fractal *fractal);
int			mouse_press(int button, int x, int y, t_fractal *fractal);
void		handle_zoom_and_offset(int button, int x, int y, t_fractal *fractal);
int			exit_fractal(t_fractal *fractal);
int			error_message(char *message);

#endif
