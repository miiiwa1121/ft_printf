# ft_printf
make

./src
cc *.c -I../include -I../libft -L../libft -lft -o ft_printf

leaks
valgrind --leak-check=full ./ft_printf

-------------------------------------------------------------------------

%c：1文字を出力
%s：文字列を出力
%p：ポインタを16進数で表示
%d：10進数の整数を出力
%i：10進数の整数を出力
%u：符号なし10進数を出力
%x：16進数（小文字）を出力
%X：16進数（大文字）を出力
%%：パーセント記号を出力

-------------------------------------------------------------------------

unsigned long long	0 ～ 18,446,744,073,709,551,615

-------------------------------------------------------------------------

可変長引数・・・個数，型の定まっていない引数

int printf( const char *format, ... );

...の部分に任意個数の引数が書けます。


va_list型とそれを操作するマクロ群（va_start,va_arg,va_end）

va_list: 可変長引数を扱うための型。stdarg.hで定義。
va_start: 可変長引数を処理するための初期化マクロ。最初の引数はva_list型の変数で、2番目は最後の固定引数です。
va_arg: 可変長引数の次の値を取得するためのマクロ。取得したいデータ型を指定します。
va_end: 可変長引数の処理が終わったら呼び出すマクロ。

va_listは
typedef char* va_list
と定義されています。ただのchar型のポインタ
va_startマクロは可変長引数の列の最初の変数へのポインタをva_list型変数（char*型だ）に設定しているだけ

挙動例
Printf( "%d %f %s\n", 100, 3.14, "piyo" );

ポインタ  apからのオフセット  値	　            　型（サイズ） 　　　
ap->      0	                100	              　　int型(4バイト)
          4	                3.14	          　　double型(8バイト)
          12	            "piyo"を指すポインタ　char*型(4バイト：32bitの場合)

フォーマット文字列は"%d %f %s\n"
最初は、"%d" → int型、apからint型の100を取り出してapを4バイト進める
次は、"%f" → double型、apからdouble型の3.14を取り出してapを8バイト進める
最後は、"%s" → char*型、apからchar型のポインタを取り出してapを4バイト進める

-------------------------------------------------------------------------

問１
ft_print_char 関数の引数が int 型で宣言されているにもかかわらず、ft_print_char(str[i]); の str[i] が char 型であることが正しいのか？
A.
Cでは char が int に自動的に昇格される
C言語では、関数に引数を渡す際に、char 型（1バイト）は int 型（通常は4バイト）に自動的に昇格されます。これは「整数昇格（integer promotion）」と呼ばれるルールに従っており、ft_print_char に char 型の値（str[i]）を渡すと、暗黙的に int 型に変換されます。

問2
桁数を返す理由は何？
A.
len を最終的に返す理由は、出力した文字数を呼び出し元に返すためです。これは、標準の printf 関数の仕様に倣っています。printf は、フォーマットに従って出力された文字数を返します。
