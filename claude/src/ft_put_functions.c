/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:45:25 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/14 19:07:34 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_base(unsigned long n, char *base, int base_len)
{
	int	count;

	count = 0;
	if (n >= (unsigned long)base_len)
		count += ft_putnbr_base(n / base_len, base, base_len);
	count += ft_putchar(base[n % base_len]);
	return (count);
}
