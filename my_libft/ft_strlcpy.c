/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:46:40 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/17 00:46:40 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;
	size_t	src_len;

	pos = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize > 0)
	{
		while (src[pos] != '\0' && pos < dstsize -1)
		{
			dst[pos] = src[pos];
			pos++;
		}
		dst[pos] = '\0';
	}
	return (src_len);
}

// int main() {
//     char src[] = "Hello, world!";
//     char dst1[50];
//     char dst2[5];
//     char dst3[14];  // 13 characters + null terminator
//     size_t len1 = ft_strlcpy(dst1, src, sizeof(dst1));
//     printf("Copied '%s' into dst1, length: %zu\n", dst1, len1);
//     size_t len2 = ft_strlcpy(dst2, src, sizeof(dst2));
//     printf("Copied '%s' into dst2, length: %zu\n", dst2, len2);
//     size_t len3 = ft_strlcpy(dst3, src, sizeof(dst3));
//     printf("Copied '%s' into dst3, length: %zu\n", dst3, len3);
//     return 0;
// }
