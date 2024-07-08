#include "ft_printf.h"

int ft_print_integer(int n)
{
    int len;
    char *num;

    len = 0;
    num = ft_itoa(n);
    len = ft_print_string(num);
    free(num);
    return (len);
}