/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:16:22 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/23 22:16:22 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
// int main() {
//     char ch = '%';
//     if(ft_isascii(ch)) {
//         printf("'%c' is an ASCII character.\n", ch);
//     } else {
//         printf("'%c' is not an ASCII character.\n", ch);
//     }

//     return 0;
// }
