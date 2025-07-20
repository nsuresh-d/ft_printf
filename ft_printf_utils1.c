/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuresh- <nsuresh-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 03:08:39 by nsuresh-          #+#    #+#             */
/*   Updated: 2025/07/14 03:08:39 by nsuresh-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	printf_string(char *s, int *count)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		printf_char(s[i], count);
		i++;
	}
}

static void	printf_int_recursive(long n, int *count)
{
	if (n >= 10)
		printf_int_recursive(n / 10, count);
	printf_char((n % 10) + '0', count);
}

void	printf_int(int n, int *count)
{
	long	num;

	num = n;
	if (num < 0)
	{
		printf_char('-', count);
		num = -num;
	}
	printf_int_recursive(num, count);
}

void	printf_unsigned(unsigned int n, int *count)
{
	if (n >= 10)
		printf_unsigned(n / 10, count);
	printf_char((n % 10) + '0', count);
}
