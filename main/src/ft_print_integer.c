/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:10:24 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/09/27 12:09:49 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_print_integer(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);//int to string
	if (!num)
	    return(NULL)
	len = ft_print_string(num);//文字列出力
	free(num);//itoa内のmallocをfree
	return (len);
}
