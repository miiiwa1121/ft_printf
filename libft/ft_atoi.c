/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsubasa <mtsubasa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:46:53 by mtsubasa          #+#    #+#             */
/*   Updated: 2024/07/11 09:24:58 by mtsubasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int ft_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r');
}

static long long handle_overflow(long long n, char digit, int sign)
{
    if (sign > 0)
    {
        if (n > LONG_MAX / 10 || (n == LONG_MAX / 10 && digit > LONG_MAX % 10))
            return LONG_MAX;
    }
    else
    {
        if (n > -(LONG_MIN / 10) || (n == -(LONG_MIN / 10) && digit > -(LONG_MIN % 10)))
            return LONG_MIN;
    }
    return n * 10 + digit * sign;
}

int ft_atoi(const char *str)
{
    long long result = 0;
    int sign = 1;

    while (ft_isspace(*str))
        str++;

    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;

    while (ft_isdigit(*str))
    {
        result = handle_overflow(result, *str - '0', sign);
        if (result == LONG_MAX || result == LONG_MIN)
            return (int)result;
        str++;
    }

    return (int)(result * sign);
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
