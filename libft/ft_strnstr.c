/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:33:39 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/05/12 17:49:13 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	int				j;

	j = 0;
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i] == needle[j] && haystack[i] && i < len)
		{
			i++;
			j++;
		}
		if (!needle[j])
			return ((char *)&haystack[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}

// int	main(void)
// {
// 	// const char	haystack[20] = "TutorialsPoint";
// 	// const char	needle[10] = "to";
// 	char		*result;

// 	result = ft_strnstr("abbbcdefg", "bbc", 20);
// 	printf("The substring is: %s\n", result);
// 	return (0);
// }
