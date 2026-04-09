/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:54:42 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 10:27:53 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static char	*ft_revcpy_i(char *str)
{
	int		i;
	int		j;
	char	*ret;

	j = 0;
	i = ft_strlen(str);
	if (i == 0)
	{
		ret = "0";
		return (ft_strdup(ret));
	}
	ret = malloc(i * sizeof(char) + 1);
	if (!ret)
		return (NULL);
	i--;
	while (i >= 0)
	{
		ret[j] = str[i];
		j++;
		i--;
	}
	ret[j] = '\0';
	return (ret);
}

char	*ft_itoa(int n)
{
	int		i;
	int		tmp;
	char	str[12];

	i = 0;
	tmp = n;
	if (tmp == -2147483648)
	{
		str[i] = '8';
		tmp = -214748364;
		i++;
	}
	if (tmp < 0)
		tmp = -tmp;
	while (tmp > 0)
	{
		str[i] = (tmp % 10) + '0';
		tmp = tmp / 10;
		i++;
	}
	str[i] = '\0';
	str[i + 1] = '\0';
	if (n < 0)
		str[i] = '-';
	return (ft_revcpy_i(str));
}
/*
-------------------------------------ITOA---------------------------------------
/!\ The function write the number in mirror and reverse it with revcpy. /!\

Check in case ofoverflow when n = -2^31.
If n is negative, reverse sign.
Add the number in the string, use '%' to get the next number and use '/'
to delete this number and continue until all numbers are added in str.
Add TWO /0 and replace the first one with '-' if n is negative.
Return revcpy.

------------------------------------REVCPY--------------------------------------
If the string is empty, set ret to 0 and create the string with "ft_strdup".
Malloc with the len + 1 (for /0) and return NULL if Malloc failed.
Copy the original string in reverse to get the number in the correct order.
*/
