/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:46:53 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/06/17 17:46:57 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while ((*str >= '\011' && *str <= '\015') || *str == '\040')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (*str == '+' || *str == '-')
			return (0);
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("Test 1: \"%s\" -> %d\n", "+-54", ft_atoi("+-54"));      
// 		// Expected: 0
// 	printf("Test 2: \"%s\" -> %d\n", "-+48", ft_atoi("-+48"));      
// 		// Expected: 0
// 	printf("Test 3: \"%s\" -> %d\n", "   -123", ft_atoi("   -123"));
// 		// Expected: -123
// 	printf("Test 4: \"%s\" -> %d\n", "+42", ft_atoi("+42"));        
// 		// Expected: 42
// 	printf("Test 5: \"%s\" -> %d\n", "   +007", ft_atoi("   +007"));
// 		// Expected: 7
// 	printf("Test 6: \"%s\" -> %d\n", "- 54", ft_atoi("- 54"));      
// 		// Expected: 0
// 	return (0);
// }
