/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:29:08 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/23 22:29:08 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c)
{
	unsigned char	ch;

	if (c > 128)
		return (0);
	ch = (unsigned char) c;
	if (ch >= 32 && ch < 127)
		return (1);
	else
		return (0);
}

// int main()
// {
// int	ch = 288;
// 	if (ft_isprint(ch))
// 		printf("'%i' is a printable character.\n", ch);
// 	else
// 		printf("'%c' is not a printable character.\n", ch);
// 	return 0;
// }
