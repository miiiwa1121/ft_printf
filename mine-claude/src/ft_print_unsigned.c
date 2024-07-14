/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:11:37 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/14 22:48:32 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static void	ft_put_unsigned(unsigned int n)
{
	if (n > 9)
		ft_put_unsigned(n / 10);
	ft_print_char(n % 10 + '0');
}

int	ft_print_unsigned(unsigned int n)
{
	int len;

	len = ft_num_len(n);
	if (n == 0)
		ft_print_char('0');
	else
		ft_put_unsigned(n);
	return (len);
}
