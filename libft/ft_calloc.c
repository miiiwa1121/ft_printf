/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:50:45 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/16 18:30:35 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	size_t	count;
// 	size_t	size;
// 	int		*arr;

// 	count = 9;
// 	size = sizeof(int);
// 	arr = ft_calloc(count, size);
// 	if (arr == NULL)
// 	{
// 		printf("メモリの割り当てに失敗しました。\n");
// 		return (1);
// 	}
// 	for (size_t i = 0; i < count; i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// 	free(arr);
// 	return (0);
// }
