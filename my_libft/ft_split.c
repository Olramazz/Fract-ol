/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:36:29 by olramazz          #+#    #+#             */
/*   Updated: 2023/12/05 20:36:29 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

static size_t	w_count(char const *s, char c)
{
	size_t	i;
	size_t	wn;

	i = 0;
	wn = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			wn++;
		while (s[i] != c && s[i])
			i++;
	}
	return (wn);
}

static size_t	w_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	matrix_free(char **m)
{
	size_t	i;

	i = 0;
	if (!m)
		return ;
	while (m[i])
	{
		free(m[i]);
		m[i] = NULL;
		i++;
	}
	free(m);
	m = NULL;
}

static char	**str_new(char **m, const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (*s && *s != c)
				len = w_len(s, c);
			m[i] = ft_substr(s, 0, len);
			if (!m[i])
			{
				matrix_free(m);
				return (NULL);
			}
			i++;
			s += len;
		}
	}
	m[i] = NULL;
	return (m);
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	result = ft_calloc((w_count(s, c) + 1) * sizeof(char *), 1);
	if (!result || !s)
		return (NULL);
	result = str_new (result, s, c);
	return (result);
}
