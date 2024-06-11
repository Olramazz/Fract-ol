/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:43:16 by olramazz          #+#    #+#             */
/*   Updated: 2024/06/04 21:13:57 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	int	is_space;

	is_space = 0;
	is_space |= (c == ' ');
	is_space |= (c == '\n');
	is_space |= (c == '\t');
	is_space |= (c == '\v');
	is_space |= (c == '\f');
	is_space |= (c == '\r');
	return (is_space);
}
