/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsuresh- <nsuresh-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:46:09 by nsuresh-          #+#    #+#             */
/*   Updated: 2025/07/14 02:46:09 by nsuresh-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
void	process_format(const char *format, va_list *args, int *count);
void	handle_specifier(char specifier, va_list *args, int *count);
void	printf_char(char c, int *count);
void	printf_string(char *s, int *count);
void	printf_int(int n, int *count);
void	printf_unsigned(unsigned int n, int *count);
void	printf_hex(unsigned int n, int uppercase, int *count);
void	printf_pointer(void *ptr, int *count);

#endif