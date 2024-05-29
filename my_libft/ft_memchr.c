/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:30:38 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/15 21:30:38 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *source, int charset, size_t n_bytes)
{
	const unsigned char	*source_holder;
	unsigned char		charset_holder;
	int					i;

	source_holder = (unsigned char *)source;
	charset_holder = (unsigned char)charset;
	i = 0;
	while (n_bytes--)
	{
		if (source_holder[i] == charset_holder)
			return ((void *)&source_holder[i]);
		i++;
	}
	return (NULL);
}
