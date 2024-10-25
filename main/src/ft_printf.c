/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:09:17 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/10/25 19:30:16 by mtsubasa         ###   ########.fr       */
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

#include <stdio.h>
#include <limits.h>

int main() {

    // テストケース1: 単一の文字
    ft_printf("c:::単一の文字::::::::::::::::::%c,%c\n", 'A', 'B');
    printf("c:::単一の文字::::::::::::::::::%c,%c\n\n", 'A', 'B');

    // 拡張: 特殊文字
    ft_printf("c:::単一の文字(スペース):::::::::%c\n", ' ');
    printf("c:::単一の文字(スペース):::::::::%c\n\n", ' ');

    ft_printf("c:::単一の文字(改行):::::::::::%c\n", '\n');
    printf("c:::単一の文字(改行):::::::::::%c\n\n", '\n');

    // テストケース2: 文字列
    ft_printf("s:::文字列:::::::::::::::::::::%s\n", "world");
    printf("s:::文字列:::::::::::::::::::::%s\n\n", "world");

    // テストケース2.2: 空文字列
    ft_printf("空文字列::::::%s\n", "");
    printf("空文字列::::::%s\n\n", "");

    // テストケース2.3: NULLポインタ
    ft_printf("NULLポインタ:::::: %s\n", NULL);
    printf("NULLポインタ:::::: %s\n\n", "(null)");//未定義動作

    // テストケース2.4: 長い文字列
    ft_printf("長い文字列:::::::::::%s\n", "This is a very long string to test the ft_printf function.");
    printf("長い文字列:::::::::::%s\n\n", "This is a very long string to test the ft_printf function.");

    // 拡張: 特殊文字を含む文字列
    ft_printf("s:::特殊文字の文字列:::::::::::%s\n", "Hello, \tWorld! \nNewline");
    printf("s:::特殊文字の文字列:::::::::::%s\n\n", "Hello, \tWorld! \nNewline");

    // テストケース3: ポインタ
    ft_printf("p:::ポインタ引数を16進数形式::::::%p\n", &main);
    printf("p:::ポインタ引数を16進数形式::::::%p\n\n", &main);

    // テストケース3.1: NULLポインタのポインタ表示
    ft_printf("NULLポインタのポインタ::::::%p\n", NULL);
    printf("NULLポインタのポインタ::::::%p\n\n", NULL);

    // テストケース4: 10進数
    ft_printf("d:::10進数:::::::::::::::::::::%d\n", 0);
    printf("d:::10進数:::::::::::::::::::::%d\n\n", 0);

    // テストケース4.1: 大きな整数
    ft_printf("大きな整数:::::::::::::::::%d\n", INT_MAX);
    printf("大きな整数:::::::::::::::::%d\n\n", INT_MAX);

    // テストケース4.2: 小さな整数
    ft_printf("小さな整数:::::::::::::::::%d\n", INT_MIN);
    printf("小さな整数:::::::::::::::::%d\n\n", INT_MIN);

    // テストケース5: 10進数の整数
    ft_printf("i:::10進数:::::::::::::::::::::%i\n", 0);
    printf("i:::10進数:::::::::::::::::::::%i\n\n", 0);

    // テストケース5.1: 大きな整数
    ft_printf("大きな整数:::::::::::::::::%i\n", INT_MAX);
    printf("大きな整数:::::::::::::::::%i\n\n", INT_MAX);

    // テストケース5.2: 小さな整数
    ft_printf("小さな整数:::::::::::::::::%i\n", INT_MIN);
    printf("小さな整数:::::::::::::::::%i\n\n", INT_MIN);

    // テストケース6: 符号なし10進数
    ft_printf("u:::符号なし10進数::::::::::::::%u\n", 0);
    printf("u:::符号なし10進数::::::::::::::%u\n\n", 0);

    // テストケース6.1: 負の符号なし整数
    ft_printf("負の符号なし整数:::::::::::::::%u\n", -1);
    printf("負の符号なし整数:::::::::::::::%u\n\n", -1);

    // テストケース6.2: 大きな符号なし整数
    ft_printf("大きな符号なし整数:::::::::::::::%u\n", UINT_MAX);
    printf("大きな符号なし整数:::::::::::::::%u\n\n", UINT_MAX);

    // テストケース7: 16進数の小文字形式
    ft_printf("x:::16進数の小文字形式:::::::::::%x\n", 255);
    printf("x:::16進数の小文字形式:::::::::::%x\n\n", 255);

    // 拡張: 境界値の16進数
    ft_printf("x:::境界値 (UINT_MAX):::::::::::%x\n", UINT_MAX);
    printf("x:::境界値 (UINT_MAX):::::::::::%x\n\n", UINT_MAX);

    // テストケース8: 16進数の大文字形式
    ft_printf("X:::16進数の大文字形式:::::::::::%X\n", 255);
    printf("X:::16進数の大文字形式:::::::::::%X\n\n", 255);

    // 拡張: 負数の16進数
    ft_printf("x:::負数 (負の16進数):::::::::::%x\n", -1);
    printf("x:::負数 (負の16進数):::::::::::%x\n\n", -1);

    // テストケース9: パーセント記号
    ft_printf("パーセント記号:%%\n");
    printf("パーセント記号:%%\n\n");

    // テストケース9.1: パーセント記号を2つ連続
    ft_printf("パーセント記号2つ連続:%%%%\n");
    printf("パーセント記号2つ連続:%%%%\n\n");

    // テストケース10: 複数のフォーマット指定子
    ft_printf("複数のフォーマット指定子::::::%d, %s, %c, %x, %p, %%\n", 42, "answer", 'A', 255, &main);
    printf("複数のフォーマット指定子::::::%d, %s, %c, %x, %p, %%\n\n", 42, "answer", 'A', 255, &main);

    // 拡張: 負数を含む複合フォーマット
    ft_printf("複数のフォーマット(負数): %d, %s, %c, %x, %p, %%\n", -42, "negative", 'Z', -255, &main);
    printf("複数のフォーマット(負数): %d, %s, %c, %x, %p, %%\n\n", -42, "negative", 'Z', -255, &main);

    return 0;
}
