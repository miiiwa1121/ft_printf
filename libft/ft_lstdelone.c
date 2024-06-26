/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:41:15 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 09:54:51 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del_func(void *data)
// {
// 	free(data);
// }

// int	main(void)
// {
// 	t_list	*node_to_delete;

// 	// リストを操作するコード...
// 	node_to_delete = /* 削除するノード */;
// 	ft_lstdelone(node_to_delete, &del_func); // ノードの削除
// 	// ノードを削除した後の処理...
// 	return (0);
// }
