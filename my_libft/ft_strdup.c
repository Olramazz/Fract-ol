/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:07:08 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/30 01:07:08 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*buf;
	char	*original_buf;

	buf = malloc(ft_strlen(s) + 1);
	if (buf == NULL)
		return (NULL);
	original_buf = buf;
	while (*s)
		*buf++ = *s++;
	*buf = '\0';
	return (original_buf);
}

// int main() {
//     const char *original = "Hello, world!";
//     char *copy = ft_strdup(original);
//     if (copy == NULL) {
//         perror("strdup failed");
//         return 1;
//     }
//     printf("Original: %s\nCopy: %s\n", original, copy);
//     free(copy); // Don't forget to free the memory
//     return 0;
// }
