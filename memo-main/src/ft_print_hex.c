/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:09:59 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/08/09 23:44:28 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_hex_len(unsigned int num)
{
	int		len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int num, char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');//
		else
		{
			if (format == 'x')//小文字
				ft_print_char(num - 10 + 'a');
			if (format == 'X')//大文字
				ft_print_char(num - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int num, char format)//16進数変換、formatは大文字小文字の判断
{
	if (num == 0)
		return (ft_print_char('0'));
	else
		ft_put_hex(num, format);//引数とx or X
	return (ft_hex_len(num));
}
