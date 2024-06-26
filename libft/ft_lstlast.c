/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:40:28 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 13:21:32 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main() {
//     t_list *head = NULL; // リストの先頭ポインタ

//     // リストに要素を追加する処理...

//     t_list *lastNode = ft_lstlast(head); // リストの最後のノードを取得
//     if (lastNode)
//         printf("リストの最後のノードのデータ: %p\n", lastNode->data);
//     else
//         printf("リストが空です。\n");

//     return (0);
// }
