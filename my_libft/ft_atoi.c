/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:26:16 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/23 01:26:16 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	ft_di(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	ft_minus(int sign, int result)
{
	if (sign == 1)
		return (0);
	return (-result);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	prev_result;

	result = 0;
	sign = 1;
	while (ft_space(*str))
		str++;
	sign = ft_sign(&str);
	while (ft_di(*str))
	{
		prev_result = result;
		result = result * 10 + (*str - '0');
		if ((result / 10) != prev_result)
			return (ft_minus(sign, result));
		str++;
	}
	return (result * sign);
}
