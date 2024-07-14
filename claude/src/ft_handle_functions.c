/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:45:32 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/14 19:07:32 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(va_list args)
{
	return (ft_putchar(va_arg(args, int)));
}

int	handle_string(va_list args)
{
	return (ft_putstr(va_arg(args, char *)));
}

int	handle_pointer(va_list args)
{
	unsigned long	ptr;
	int				count;

	ptr = va_arg(args, unsigned long);
	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr_base(ptr, "0123456789abcdef", 16);
	return (count);
}

int	handle_int(va_list args)
{
	return (ft_putnbr(va_arg(args, int)));
}

int	handle_unsigned(va_list args)
{
	return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10));
}

int	handle_hex_lower(va_list args)
{
	return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", 16));
}

int	handle_hex_upper(va_list args)
{
	return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
}

int	handle_percent(void)
{
	return (ft_putchar('%'));
}
