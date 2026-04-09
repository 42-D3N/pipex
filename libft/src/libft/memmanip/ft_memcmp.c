/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:27:53 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 12:59:26 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				diff;
	int				i;
	unsigned int	c1;
	unsigned int	c2;
	unsigned char	*str;

	diff = 0;
	i = 0;
	while (diff == 0 && n > 0)
	{
		str = (unsigned char *) s1;
		c1 = (unsigned int) str[i];
		str = (unsigned char *) s2;
		c2 = (unsigned int) str[i];
		if (c1 > c2 || c1 < c2)
			return (diff = c1 - c2);
		i++;
		n--;
	}
	return (0);
}
/*
Until no difference is found, and until size is equal to 0 :
- Get the character of s1 in c1 and get the character of s2 in c2.
- Calculate the difference and return it if one is lesser or greater.
- Increment i to check the next character and decrement size.
Return 0 if no difference is found.
*/
