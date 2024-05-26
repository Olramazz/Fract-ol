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

#include <mlx.h>
#include <math.h>

typedef struct t_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*color;
	double	zoom;
	char	*name;
	int		max_iter;
	double	x;
	double	y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;

}				t_fractal;