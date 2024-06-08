/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:17:08 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/16 21:17:08 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)str;
	while (len > 0)
	{
		p[len - 1] = 0;
		--len;
	}
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     // Test Case 1: Zero out the entire string
//     char test1[] = "Hello, World!";
//     ft_bzero(test1, strlen(test1));
//     printf("Test Case 1: \"%s\"\n", test1);  // Expected output: ""
//     // Test Case 2: Zero out a portion of the string
//     char test2[] = "Testing123";
//     ft_bzero(test2, 4);
//     printf("Test Case 2: \"%s\"\n", test2);  // Expected output: ""
//     // Test Case 3: Zero out an array of integers
//     int test3[] = {1, 2, 3, 4, 5};
//     ft_bzero(test3, sizeof(test3));
//     printf
//     Test Case 4: Zero out an empty string
//     char test4[] = "";
//     ft_bzero(test4, 0);
//     printf("Test Case 4: \"%s\"\n", test4);  // Expected output: ""
//    return 0;
// }
