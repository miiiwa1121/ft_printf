/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 07:02:23 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/23 00:04:40 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest_len = 0;
	i = 0;
	while (dst[dest_len] && dest_len < dstsize)
		dest_len++;
	if (dest_len < dstsize)
	{
		while (src[i] && dest_len + i < dstsize - 1)
		{
			dst[dest_len + i] = src[i];
			i++;
		}
		dst[dest_len + i] = '\0';
	}
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	char	dest[10] = "12345";
// 	char	src[] = "42tokyo";
// 	size_t	result;

// 	result = ft_strlcat(dest, src, 0);
// 	printf("%zu\n", result);
// 	printf("%s\n", dest);
// 	result = strlcat(dest, src, 0);
// 	printf("%zu\n", result);
// 	printf("%s\n", dest);
// 	return (0);
// }
