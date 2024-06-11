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

int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		*str += 1;
	}
	return (sign);
}

double	parse_fraction(const char **str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	if (**str == '.')
	{
		*str += 1;
		while (ft_isdigit(**str))
		{
			fraction += (**str - '0') / divisor;
			divisor *= 10.0;
			*str += 1;
		}
	}
	return (fraction);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = get_sign(&str);
	result = 0.0;
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	result += parse_fraction(&str);
	return (result * sign);
}
