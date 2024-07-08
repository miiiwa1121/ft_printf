/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:34:05 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/08 13:21:21 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int ft_printf(const char *format, ...);
int ft_print_char(int c);
int ft_print_string(char *str);
int ft_print_pointer(unsigned long long ptr);
int ft_print_integer(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hex(unsigned int n, char format);

#endif