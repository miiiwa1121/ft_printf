/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:41:51 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 09:56:24 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

// void	del_func(void *data)
// {
// 	free(data);
// }

// int	main(void)
// {
// 	t_list	*head;

// 	// リストを操作するコード...
// 	head = /* リストの先頭ポインタ */;
// 	ft_lstclear(&head, &del_func); // リストの解放
// 	// リストを解放した後の処理...
// 	return (0);
// }
