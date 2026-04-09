/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:38:35 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 11:35:40 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*address;
	int		i;

	address = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c % 128)
		{
			address = (char *)s + i;
			return (address);
		}
		i++;
	}
	if (c % 128 == 0)
		address = (char *)s + i;
	return (address);
}
/*
Stay in the first while until we don't reaches the end of s.
If the current character (% 128) is equal to the c character, return the address
of the first occurence of the character.
Otherwise, if the character is 0, return the end of the string.
*/
