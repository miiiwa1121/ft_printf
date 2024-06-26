/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:42:08 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 09:57:04 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	process_func(void *data)
// {
// 	printf("Data: %p\n", data);
// }

// int	main(void)
// {
// 	t_list	*head;

// 	// リストを操作するコード...
// 	head = /* リストの先頭ポインタ */;
// 	ft_lstiter(head, &process_func); // 各要素に関数を適用
// 	// 適用後の処理...
// 	return (0);
// }
