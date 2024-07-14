/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:34:05 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/14 19:07:54 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_printf(const char *format, ...);
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(long n);
int ft_putnbr_base(unsigned long n, char *base, int base_len);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_pointer(va_list args);
int handle_int(va_list args);
int handle_unsigned(va_list args);
int handle_hex_lower(va_list args);
int handle_hex_upper(va_list args);
int handle_percent(void);

#endif