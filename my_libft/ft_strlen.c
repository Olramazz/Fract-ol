/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:20:37 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/17 00:20:37 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *ptr)
{
	unsigned int	count_int;

	count_int = 0;
	while (ptr[count_int] != '\0')
	{
		count_int++;
	}
	return (count_int);
}

// int main() {
//     Test with an empty string
//     const char emptyString[] = "";
//     size_t lengthOfEmptyString = ft_strlen(emptyString);
//     printf("The length of an empty string is %zu.\n", lengthOfEmptyString);
//     Test with a regular string
//     const char helloString[] = "Hello";
//     size_t lengthOfHelloString = ft_strlen(helloString);
//     printf
//     Test with a string that contains spaces
//     const char spacedString[] = "Hello, world!";
//     size_t lengthOfSpacedString = ft_strlen(spacedString);
//     printf
//     Test with a string with newline character
//     const char newlineString[] = "Hello\nWorld";
//     size_t lengthOfNewlineString = ft_strlen(newlineString);
//     printf
//     Test with a string that includes escape sequences
//     const char escapeString[] = "Hello\tWorld";
//     size_t lengthOfEscapeString = ft_strlen(escapeString);
//     return 0;
// }
