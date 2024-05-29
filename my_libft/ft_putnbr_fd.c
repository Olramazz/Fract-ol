/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olramazz <olramazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:36:46 by olramazz          #+#    #+#             */
/*   Updated: 2023/11/29 01:36:46 by olramazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stddef.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

// int main()
// {
//     // Example usage of ft_putnbr_fd to print different numbers to stdout
//     ft_putnbr_fd(123, 1);  // Print "123"
//     ft_putchar_fd('\n', 1); // New line for readability
//     ft_putnbr_fd(-456, 1);  // Print "-456"
//     ft_putchar_fd('\n', 1); // New line for readability
//     ft_putnbr_fd(0, 1);    // Print "0"
//     ft_putchar_fd('\n', 1); // New line for readability
//     ft_putnbr_fd(2147483647, 1); // Print "2147483647" (max int value)
//     ft_putchar_fd('\n', 1);      // New line for readability
//     ft_putnbr_fd(-2147483648, 1); // Print "-2147483648" (min int value)
//     ft_putchar_fd('\n', 1);       // New line for readability
//     return 0;
// }
