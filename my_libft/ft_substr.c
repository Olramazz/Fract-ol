/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:51:38 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/30 01:51:38 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*buf;
	char	*original_buf;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	buf = malloc(len + 1);
	if (buf == NULL)
		return (NULL);
	original_buf = buf;
	while (len > 0 && s[start] != '\0')
	{
		*buf = s[start];
		buf++;
		start++;
		len--;
	}
	*buf = '\0';
	return (original_buf);
}
