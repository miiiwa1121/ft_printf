/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:11:19 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/14 22:48:32 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	i;

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
