#include "ft_printf.h"

static int ft_ptr_len(unsigned long long num)
{
    int len;

    len = 0;
    while (num != 0)
    {
        len++;
        num = num / 16;
    }
    return (len);
}

static void ft_put_ptr(unsigned long long num)
{
    if (num >= 16)
    {
        ft_put_ptr(num / 16);
        ft_put_ptr(num % 16);
    }
    else
    {
        if (num <= 9)
            ft_print_char(num + '0');
        else
            ft_print_char(num - 10 + 'a');
    }
}

int ft_print_pointer(unsigned long long ptr)
{
    int len;

    len = 0;
    len += ft_print_string("0x");
    if (ptr == 0)
        len += ft_print_char('0');
    else
    {
        ft_put_ptr(ptr);
        len += ft_ptr_len(ptr);
    }
    return (len);
}