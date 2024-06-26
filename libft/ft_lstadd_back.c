/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:41:01 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 13:44:53 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		temp = *lst;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

// int	main(void)
// {
// 	t_list *head = NULL; // リストの先頭ポインタ
// 	// リストに要素を追加する処理...
// 	t_list *newNode = (t_list *)malloc(sizeof(t_list)); // 新しいノードを作成
// 	newNode->data = /* 何らかのデータ */;
// 	newNode->next = NULL; // 新しいノードの次のポインタはNULL
// 	ft_lstadd_back(&head, newNode); // リストの最後に新しいノードを追加
// 	// リストをたどって内容を表示するなどの適切な処理を行う
// 	return (0);
// }
