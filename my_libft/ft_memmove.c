/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:14:59 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/15 11:14:59 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	if (d < s)
	{
		while (num--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += num;
		s += num;
		while (num--)
			*(--d) = *(--s);
	}
	return (destination);
}

// int main()
// {
// 	char source[] = "Hello, World!";
// 	char destination[20];
// 	ft_memmove(destination, source, strlen(source) + 1);
// 	printf("Source: %s\n", source);
// 	printf("Destination: %s\n", destination);
// return 0;
// }
