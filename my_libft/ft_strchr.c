/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:10:06 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/22 20:10:06 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strchr(const char *string, int c)
{
	unsigned char		c1;
	unsigned const char	*str;

	c1 = (unsigned char)c;
	str = (unsigned const char *)string;
	while (*str != '\0')
	{
		if (*str == c1)
			return ((char *)str);
		str++;
	}
	if (c1 == '\0' )
		return ((char *)str);
	return (NULL);
}

// int main()
// {
//     const char *test_str = calloc(7, sizeof(char));
//     char toFind = '\0';
//     char *found = ft_strchr(test_str, toFind);
//     if (found != NULL) {
//         printf
//("Character '%c' found at position: %ld\n", toFind, (found - test_str));
//     } else {
//         printf
//("Character '%c' not found in the string.\n", toFind);
//     }
//     return 0;
// }
