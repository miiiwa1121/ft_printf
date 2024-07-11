#include "ft_printf.h"

int ft_print_string(char *str)//文字列
{
    int i;

    i = 0;
    if (str == NULL)
        return (ft_print_string("(null)"));
    while (str[i])
    {
        ft_print_char(str[i]);
        i++;
    }
    return (i);
}