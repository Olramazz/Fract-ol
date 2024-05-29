/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:01:00 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/13 20:01:00 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *destination, const void *source, size_t n_bytes)
{
	int				pos;
	unsigned char	*src;
	unsigned char	*dest;

	pos = 0;
	if (source == NULL && destination == NULL)
		return (destination);
	src = (unsigned char *)source;
	dest = (unsigned char *)destination;
	while (n_bytes--)
	{
		dest[pos] = src[pos];
		pos++;
	}
	return ((void *)dest);
}

// int main()
// {
// 	char string1[] = "unoduetre";
// 		printf("%s\n", string1);
// 	const char string2[] = "aaaaaaaaaaaaaa";
// 		printf("%s\n", string2);
// 	ft_memcpy(&string1[2], &string2[5], 3);
// 		printf("%s", string1);
// }
