/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:40:08 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 09:50:30 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int	main(void)
// {
// 	t_list *head = NULL; // リストの先頭ポインタ
// 	// リストに要素を追加する処理...
// 	int size = ft_lstsize(head); // リストのサイズを取得
// 	printf("リストのサイズ: %d\n", size);
// 	return (0);
// }
