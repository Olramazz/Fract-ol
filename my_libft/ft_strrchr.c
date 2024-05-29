/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:24:06 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/22 21:24:06 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	const char		*last_c;
	unsigned char	c1;

	last_c = NULL;
	c1 = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == c1)
			last_c = str;
		str++;
	}
	if (c1 == '\0')
		return ((char *)str);
	return ((char *)last_c);
}

// int main()
// {
//     const char *test_str = "Hello, world!";
//     char toFind = 'o';
//     char *found = ft_strrchr(test_str, toFind);
//     if (found != NULL) {
//         printf
//     } else {
//         printf("Character '%c' not found in the string.\n", toFind);
//     }
//     return 0;
// }
