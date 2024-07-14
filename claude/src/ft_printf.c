/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:09:17 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/14 19:07:35 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_char(args));
	else if (specifier == 's')
		return (handle_string(args));
	else if (specifier == 'p')
		return (handle_pointer(args));
	else if (specifier == 'd' || specifier == 'i')
		return (handle_int(args));
	else if (specifier == 'u')
		return (handle_unsigned(args));
	else if (specifier == 'x')
		return (handle_hex_lower(args));
	else if (specifier == 'X')
		return (handle_hex_upper(args));
	else if (specifier == '%')
		return (handle_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += handle_conversion(format[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
