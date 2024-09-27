/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:09:17 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/09/27 11:54:14 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_format(va_list args, const char format)//formatを見てargsを振り分ける
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_print_integer(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)//printf("%d%s\n", i,j);	format=%d%s\n	...=i,j　が入る
{
	va_list		args;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(args, format);//argsの中に、引数が全部格納される。
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(args, format[i + 1]);//n番目の引数と%の後ろの記号が渡される
			i++;
		}
		else
			len += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

#include<stdio.h>
#include <limits.h>

int main() {

    // テストケース1: 単一の文字
    ft_printf("c:::単一の文字::::::::::::::::::%c,%c\n", 'A', 'B');
    printf("c:::単一の文字::::::::::::::::::%c,%c\n\n", 'A', 'B');

    // テストケース2: 文字列
    ft_printf("s:::文字列:::::::::::::::::::::%s\n", "world");
    printf("s:::文字列:::::::::::::::::::::%s\n\n", "world");

    // テストケース3: ポインタ
    ft_printf("p:::ポインタ引数を16進数形式::::::%p\n", &main);
    printf("p:::ポインタ引数を16進数形式::::::%p\n\n", &main);

    // テストケース4: 10進数
    ft_printf("d:::10進数:::::::::::::::::::::%d\n", -1234567890);
    printf("d:::10進数:::::::::::::::::::::%d\n\n", -1234567890);

    // テストケース5: 10進数の整数
    ft_printf("i:::10進数の整数::::::::::::::::%i\n", 12311);
    printf("i:::10進数の整数::::::::::::::::%i\n\n", 12311);

    // テストケース6: 符号なし10進数
    ft_printf("u:::符号なし10進数::::::::::::::%u\n", 123);
    printf("u:::符号なし10進数::::::::::::::%u\n\n", 123);

    // テストケース7: 16進数の小文字形式
    ft_printf("x:::16進数の小文字形式:::::::::::%x\n", 255);
    printf("x:::16進数の小文字形式:::::::::::%x\n\n", 255);

    // テストケース8: 16進数の大文字形式
    ft_printf("X:::16進数の大文字形式:::::::::::%X\n", 255);
    printf("X:::16進数の大文字形式:::::::::::%X\n\n", 255);

    // テストケース9: パーセント記号
    ft_printf("パーセント記号:%%\n");
    printf("パーセント記号:%%\n\n");

    // 追加テストケース
    // テストケース10: 空文字列
    ft_printf("空文字列::::::%s\n", "");
    printf("空文字列::::::%s\n\n", "");

    // テストケース11: NULLポインタ
    // ft_printf("NULLポインタ::::::%s\n", NULL);
    // printf("NULLポインタ::::::%s\n\n", NULL);
    ft_printf("NULLポインタ:::::: %s\n", NULL);
    printf("NULLポインタ:::::: %s\n\n", "(null)");

    // テストケース12: 長い文字列
    ft_printf("長い文字列:::::::::::%s\n", "This is a very long string to test the ft_printf function.");
    printf("長い文字列:::::::::::%s\n\n", "This is a very long string to test the ft_printf function.");

    // テストケース13: 大きな整数
    ft_printf("大きな整数:::::::::::::::::%d\n", 2147483647);
    printf("大きな整数:::::::::::::::::%d\n\n", 2147483647);

    // テストケース14: 小さな整数
    // ft_printf("小さな整数:::::::::::::::::%d\n", -2147483648);
    // printf("小さな整数:::::::::::::::::%d\n\n", -2147483648);
    ft_printf("小さな整数:::::::::::::::::%d\n", INT_MIN);
    printf("小さな整数:::::::::::::::::%d\n\n", INT_MIN);

    // テストケース15: 複数のフォーマット指定子
    ft_printf("複数のフォーマット指定子::::::%d, %s, %c, %x, %p, %%\n", 42, "answer", 'A', 255, &main);
    printf("複数のフォーマット指定子::::::%d, %s, %c, %x, %p, %%\n\n", 42, "answer", 'A', 255, &main);

    // テストケース16: 負の符号なし整数
    ft_printf("負の符号なし整数:::::::::::::::%u\n", -1);
    printf("負の符号なし整数:::::::::::::::%u\n\n", -1);

    // テストケース17: 大きな符号なし整数
    // ft_printf("大きな符号なし整数:::::::::::::::%u\n", 4294967295);
    // printf("大きな符号なし整数:::::::::::::::%u\n\n", 4294967295);
    ft_printf("大きな符号なし整数:::::::::::::::%u\n", UINT_MAX);
    printf("大きな符号なし整数:::::::::::::::%u\n\n", UINT_MAX);
    return 0;
}
