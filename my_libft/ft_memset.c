/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:56:01 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/16 21:56:01 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>

void	*ft_memset(void *string, int charset, size_t lenght)
{
	char	*str;

	str = (char *)string;
	while (lenght > 0)
	{
		*str = charset;
		str++;
		lenght--;
	}
	return (string);
}

// int main()
// {
// 	char string[] = "unoduetre";
// 	printf("%s\n", string);
// 	ft_memset(string, '?', 5);
// 	printf("%s", string);
// }
