/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:04:21 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 09:46:22 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*newNode;

// 	head = NULL;
// 	newNode = (t_list *)malloc(sizeof(t_list));
// 	newNode->data = 42;
// 	newNode->next = NULL;
// 	ft_lstadd_front(&head, newNode);
// 	return (0);
// }
