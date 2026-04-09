/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:47:15 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 10:54:59 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*address;
	size_t			i;

	str = (unsigned char *) s;
	address = 0;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
		{
			address = (unsigned char *)str + i;
			return (address);
		}
		i++;
	}
	if (c == 0 && i < n)
		address = (unsigned char *)str + i;
	return (address);
}
/*
Create 'str' and initialize his value to an unsigned char * of s.
Check if the size is not zero.
While n is less than i, if the byte matches to c, initialize the address
to the initial pointer + i to point the correct byte.
Retrurn adress.
If c is not found, and if c is the NULL character, return address as the end of
the string.
*/
