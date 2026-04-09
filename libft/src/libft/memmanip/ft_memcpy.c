/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:43:20 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 11:01:09 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*str;
	unsigned char	*t;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	str = (unsigned char *) dest;
	t = (unsigned char *) src;
	while (n > 0)
	{
		str[i] = t[i];
		i++;
		n--;
	}
	return (dest);
}
/*
If dest and src are empty, return NULL.
Cast in unsigned char * dest and src to 2 new string to copy src in dest.
Copy src in dest.
Return dest after src as been copied.
*/
