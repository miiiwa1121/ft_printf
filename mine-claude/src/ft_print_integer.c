/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:10:24 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/14 22:48:10 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_number(unsigned int num)
{
	if (num > 9)
		ft_print_number(num / 10);
	ft_print_char((num % 10) + '0');
}

static int	ft_num_len(int n)
{
	int				len;
	unsigned int	num;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)n;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_print_integer(int n)
{
	int len;
	unsigned int num;

	len = ft_num_len(n);
	if (n == 0)
		return (ft_print_char('0'));
	if (n < 0)
	{
		ft_print_char('-');
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)n;
	ft_print_number(num);
	return (len);
}
