/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:40:56 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 10:05:42 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10;
		res = res + nptr[i] - 48;
		i++;
	}
	res = res * sign;
	return (res);
}
/*
1st while : Ignore all isspace(3).
1st if : Check if sign is positive or negative, if positive, keep in 'sign'.
Second while : 
- Multiply the result and add the new number as unit.
- Increment i to get the next number until all numbers are copied.
Multiply the result with 'sign' to get, if negative, the new sign.
Return the result.
*/
