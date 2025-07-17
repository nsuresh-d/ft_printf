/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuresh- <nsuresh-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 03:16:56 by nsuresh-          #+#    #+#             */
/*   Updated: 2025/07/14 03:16:56 by nsuresh-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_hex(unsigned int n, int uppercase, int *count)
{
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		printf_hex(n / 16, uppercase, count);
	printf_char(base[n % 16], count);
}

void	printf_pointer(void *ptr, int *count)
{
	uintptr_t	n;

	n = (uintptr_t)ptr;
	printf_string("0x", count);
	if (n == 0)
	{
		printf_char('0', count);
		return ;
	}
	print_ptr_recursive(n, count);
}

static void	print_ptr_recursive(uintptr_t n, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		print_ptr_recursive(n / 16, count);
	printf_char(base[n % 16], count);
}
