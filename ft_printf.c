/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuresh- <nsuresh-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:44:29 by nsuresh-          #+#    #+#             */
/*   Updated: 2025/07/14 02:44:29 by nsuresh-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	process_format(format, &args, &count);
	va_end(args);
	return (count);
}

void	process_format(const char *format, va_list *args, int *count)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			handle_specifier(format[i + 1], args, count);
			i++;
		}
		else
			printf_char(format[i], count);
		i++;
	}
}

void	handle_specifier(char specifier, va_list *args, int *count)
{
	if (specifier == 'c')
		printf_char(va_arg(*args, int), count);
	else if (specifier == 's')
		printf_string(va_arg(*args, char *), count);
	else if (specifier == 'd' || specifier == 'i')
		printf_int(va_arg(*args, int), count);
	else if (specifier == 'u')
		printf_unsigned(va_arg(*args, unsigned int), count);
	else if (specifier == 'x')
		printf_hex(va_arg(*args, unsigned int), 0, count);
	else if (specifier == 'X')
		printf_hex(va_arg(*args, unsigned int), 1, count);
	else if (specifier == 'p')
		printf_pointer(va_arg(*args, void *), count);
	else if (specifier == '%')
		printf_char('%', count);
}
