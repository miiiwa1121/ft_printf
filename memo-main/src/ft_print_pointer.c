/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:11:05 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/10/26 18:24:32 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long long num)
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

static void	ft_put_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');//9,8,7,6,5,4,3,2,1,0
		else
			ft_print_char(num - 10 + 'a');//15,14,13,12,11,10
	}
}

int	ft_print_pointer(unsigned long long ptr)//ポインタを16進数
{
	int		len;

	len = 0;
	len += ft_print_string("0x");
	if (ptr == 0)
		len += ft_print_char('0');
	else
	{
		ft_put_ptr(ptr);//
		len += ft_ptr_len(ptr);//
	}
	return (len);
}
