/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:56:13 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/29 00:56:13 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main()
// {
//     // Write a character to standard output (stdout)
//     ft_putchar_fd('A', 1);
//     // Write a newline character to standard output to move to the next line
//     ft_putchar_fd('\n', 1);
//     // Write a character to standard error (stderr)
//     ft_putchar_fd('B', 2);
//     // Write a newline character to standard error
//     ft_putchar_fd('\n', 2);
//     return (0);
// }
