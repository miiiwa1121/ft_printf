/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:06:41 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/30 15:05:03 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n-- > 0)
	{
		*ptr = '\0';
		ptr++;
	}
}

// int	main(void)
// {
// 	char	str[] = "123456789";

// 	ft_bzero(str + 2, 3);
// 	printf("%s\n", str);
// 	return (0);
// }
