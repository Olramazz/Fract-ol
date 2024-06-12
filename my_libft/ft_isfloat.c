/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:16:55 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/12 13:16:55 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isfloat(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (dot)
				return (0);
			dot = 1;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 0 || (i == 1 && dot))
		return (0);
	return (1);
}
