/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:40:20 by olramazz          #+#    #+#             */
/*   Updated: 2024/05/29 17:40:20 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

double	ft_atof(const char *str)
{
	double	result = 0.0;
	double	fraction = 1.0;
	int		sign = 1;

	while (ft_isspace(*str))
	{
		str++;
	}
	if (*str == '-' || *str == '+') {
		if (*str == '-') {
			sign = -1;
		}
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			fraction /= 10.0;
			result += (*str - '0') * fraction;
			str++;
		}
	}

	return (result * sign);
}
