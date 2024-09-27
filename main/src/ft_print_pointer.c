/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:11:05 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/09/27 12:06:48 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_ptr_len(unsigned long long num)//桁数計算
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_ptr(unsigned long long num)//16進数変換
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');//ASCII変換0123456789
		else
			ft_print_char(num - 10 + 'a');//ASCII変換abcdef
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int		len;

	len = 0;
	len += ft_print_string("0x");
	if (ptr == 0)
		len += ft_print_char('0');
	else
	{
		ft_put_ptr(ptr);//16進数変換、出力
		len += ft_ptr_len(ptr);//桁数計算
	}
	return (len);
}
