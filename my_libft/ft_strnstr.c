/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:37:14 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/22 21:37:14 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

char	*ft_strnstr(const char *src, const char *fnd, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (*fnd == '\0')
		return ((char *)src);
	while (len > 0 && src[a] != '\0')
	{
		b = 0;
		while (src[a + b] == fnd[b] && fnd[b] != '\0' && (a + b) < len)
		{
			if (fnd[b + 1] == '\0')
				return ((char *)&src[a]);
			b++;
		}
		a++;
	}
	return (NULL);
}

// int main() {
//     const char *haystack = "Hello, world!";
//     const char *needle = "world";
//     size_t len = 12; // Length to search within
//     // Test 1: Needle should be found
//     char *result = ft_strnstr(haystack, needle, len);
//     if (result != NULL) {}
//         printf
//     } else {
//         printf("Test 1 - '%s' not found in '%s'.\n", needle, haystack);
//     }
//     // Test 2: Needle should not be found (due to len limitation)
//     len = 5;
//     result = ft_strnstr(haystack, needle, len);
//     if (result != NULL) {
//         printf
//     } else {
//         printf("Test 2 - '%s' not found in '%s'.\n", needle, haystack);
//     }
//     // Test 3: Searching for an empty string
//     needle = "";
//     result = ft_strnstr(haystack, needle, len);
//     if (result != NULL) {
//         printf
//     } else {
//         printf("Test 3 - Empty string not found in '%s'.\n", haystack);
//     }
//     return 0;
// }
