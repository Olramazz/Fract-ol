/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:47:30 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/23 21:47:30 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// int main()
// {
// char	ch = 'a';
// 	if (isdigit(ch))
// 		printf("%c is a digit.\n", ch);
// 	else
// 	printf("%c is not a digit.\n", ch);
// 	if (ft_isdigit(ch))
// 		printf("%c is a digit.\n", ch);
// 	else
// 		printf("%c is not a digit.\n", ch);
// 	return 0;
// }