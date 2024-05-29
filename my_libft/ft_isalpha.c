/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:15:22 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/23 21:15:22 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// #include<ctype.h>
// int main()
// {
//     char ch = '!';
// 	if (ft_isalpha(ch))
// 		printf("%c is an alphabetic character.\n", ch);
// 	else
// 		printf("%c is not an alphabetic character.\n", ch);
// 	if (isalpha(ch))
// 		printf("%c is an alphabetic character.\n", ch);
// 	else
// 		printf("%c is not an alphabetic character.\n", ch);
// 	return 0;
// }
