/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:46:42 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/09/27 12:16:19 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	digits_len(int n)//桁数計算
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	number_sequence(int n, char *str, size_t len)
{
	unsigned int	num;

	if (n < 0)
	{
		num = -n;
	}
	else
	{
		num = n;
	}
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = (num % 10) + '0';//ASCII変換した値を、lenの後ろから詰める
		num = num / 10;
	}
	if (n < 0)
	{
		str[0] = '-';//負の数の文字
	}
}

char	*ft_itoa(int n)
{
	size_t	digits;//桁数
	char	*str;

	digits = digits_len(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));//文字型で桁数＋終端分のメモリを確保
	if (!str)
		return (NULL);
	number_sequence(n, str, digits);//引数、メモリ、桁数
	return (str);
}
