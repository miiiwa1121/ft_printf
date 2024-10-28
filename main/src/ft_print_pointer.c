/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:11:05 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/10/28 18:14:46 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_put_ptr(unsigned long long num)//16進数変換
{
	int	len;

	len = 0;
	if (num >= 16)
	{
		len += ft_put_ptr(num / 16);
		len += ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			len += ft_print_char(num + '0');//ASCII変換0123456789
		else
			len += ft_print_char(num - 10 + 'a');//ASCII変換abcdef
	}
	return (len);
}

int	ft_print_pointer(unsigned long long ptr)
{
	int		len;

	len = 0;
	if (ptr == 0)
	{
		len += ft_print_string("(nil)"); // 文字列として(nil)を出力
		return (len);
	}
	else
	{
		len += ft_print_string("0x");
		len += ft_put_ptr(ptr);//16進数変換、出力
	}
	return (len);
}
