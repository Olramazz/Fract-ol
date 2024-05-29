/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:37:09 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/29 16:37:09 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;

	ptr = malloc(num_elements * element_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, num_elements * element_size);
	return (ptr);
}
