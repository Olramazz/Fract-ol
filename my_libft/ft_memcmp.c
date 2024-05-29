/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:16:54 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/16 21:16:54 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n_bytes)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;
	size_t				i;

	ptr_s1 = (const unsigned char *)s1;
	ptr_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n_bytes)
	{
		if (ptr_s1[i] != ptr_s2[i])
			return (ptr_s1[i] - ptr_s2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
//     char str1[] = "abc";
//     char str2[] = "abd";
//     int result;

//     result = ft_memcmp(str1, str2, 3);
//     if (result > 0) {
//         printf("str1 is greater than str2\n");
//     } else if (result < 0) {
//         printf("str2 is greater than str1\n");
//     } else {
//         printf("str1 is equal to str2\n");
//     }
//     return 0;
// }
