/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:11:37 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/10/25 17:17:36 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_num_len(unsigned int num)//桁数計算
{
	int		len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);//桁数計算
	num = (char *)malloc(sizeof(char) * (len + 1));//桁数+先頭数字分のメモリを確保
	if (!num)
		return (0);
	num[len] = '\0';//NULL止め
	while (n)
	{
		num[len - 1] = n % 10 + '0';//後ろから順に、型変換(int to char)しながら引数nをnumに格納
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)//符号なし10進数
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += ft_print_char('0');
	else
	{
		num = ft_uitoa(n);//int to char
		len += ft_print_string(num);//文字列出力
		free(num);
	}
	return (len);
}
