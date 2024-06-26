/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:28:07 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 15:20:29 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static	char	*strmake(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str_tmp;

	if (!s1 || !s2)
		return (NULL);
	str = strmake(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (NULL);
	str_tmp = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str_tmp);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*text[10];
// 	char	*result;

// 	text[0] = "1";
// 	text[1] = "2";
// 	text[2] = "3";
// 	text[3] = "4";
// 	text[4] = "a";
// 	text[5] = "b";
// 	text[6] = "cd";
// 	text[7] = ">?";
// 	text[8] = ":>?";
// 	text[9] = "102";
// 	result = ft_strjoin(text[7], text[9]);
// 	if (!result)
// 	{
// 		printf("Error: memory allocation failed\n");
// 		return (1);
// 	}
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
