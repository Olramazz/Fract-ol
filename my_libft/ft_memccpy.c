/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:04:43 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/13 21:04:43 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int					pos;
	unsigned char		*d1;
	const unsigned char	*s1;

	pos = 0;
	d1 = (unsigned char *)dest;
	s1 = (const unsigned char *)src;
	while (n--)
	{
		d1[pos] = s1[pos];
		if (s1[pos] == (unsigned char)c)
		{
			return (d1 + pos + 1);
		}
		pos++;
	}
	return (NULL);
}

// int main()
// {
// 	char string1[] = "bbbbbbbbbbbb";
// 		printf("%s\n", string1);
// 	const char string2[] = "aaacaaaaaaaaa";
// 		printf("%s\n", string2);
// 	ft_memccpy(&string1[1], &string2[1],'c', 5);
// 		printf("%s", string1);
// 		char string3[] = "bbbbbbbbbbbb";
// 		printf("%s\n", string3);
// 	const char string4[] = "aaaaaaaaaaaaaa";
// 		printf("%s\n", string4);
// 	ft_memccpy(&string3[1], &string4[1],'c', 5);
// 		printf("%s", string3);
// }
