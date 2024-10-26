/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:11:19 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/10/26 18:24:32 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)//文字列
{
	int		i;

	i = 0;
	if (str == NULL)
		return (ft_print_string("(null)"));//再起して、(NULL)を表示
	while (str[i])
	{
		ft_print_char(str[i]);//引数として与えられた文字列を一文字ずつ出力
		i++;
	}
	return (i);
}
