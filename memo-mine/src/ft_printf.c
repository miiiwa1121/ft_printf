/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:09:17 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/15 13:00:04 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
		//%の後ろに一致する記号があったら、そのプログラムへ移行させる
{
	if (format == 'c') // 1文字を出力する
		return (ft_print_char(va_arg(args, int)));
	else if (format == 's') //文字列を表示する
		return (ft_print_string(va_arg(args, char *)));
	else if (format == 'p') // void * ポインタ引数は 16 進形式で表示
		return (ft_print_pointer(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i') // 10 進数を表示//10進数の整数を表示
		return (ft_print_integer(va_arg(args, int)));
	else if (format == 'u') //符号なし 10 進数（ベース 10）を表示
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X') // 16 進数の小 or 大文字形式で数値を出力
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == '%') //パーセント記号を出力
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)	//可変長引数:個数が決まってない引数
										//...の部分に任意個数の引数が書ける
										//va_start,va_arg,va_end:va_list型とそれを操作するマクロ群
{
	va_list args;	//va_list任意個の引数を１個の変数に変換
					//定義:typedef char* va_list
	int i;
	int len;

	i = 0;
	len = 0;
	va_start(args, format);	//可変長引数の列の最初の変数へのポインタをva_list型変数（char*型だ）に設定
	while (format[i])
	{
		if (format[i] == '%') //与えられた文字列の中に％を見つけたら
		{
			len += ft_format(args, format[i + 1]);
			i++;
		}
		else
			len += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
