#include "ft_printf.h"

int ft_print_char(int c)//文字
{
    return (write(1, &c, 1));
}