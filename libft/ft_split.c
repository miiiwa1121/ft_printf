/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:30:00 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/22 20:56:56 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_cword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_cword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	c;
// 	char	**result;
// 	size_t	i;

// 	char *str = "   lorem   ipsum dolor     sit amet, consectetur   "
// 				"adipiscing elit. Sed non risus. Suspendisse   ";
// 	c = ' ';
// 	result = ft_split(str, c);
// 	if (!result)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("result[%zu]: %s\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }
