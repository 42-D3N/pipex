/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:39:17 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 11:05:18 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*tmp;

	if (dest == NULL && src == NULL)
		return (NULL);
	str = (unsigned char *) dest;
	tmp = (unsigned char *) src;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			str[n - 1] = tmp[n - 1];
			n--;
		}
	}
	return (dest);
}
/*
Check if dest and src are not empty.
Cast dest and src as unsigned char * to copy src in dest.
If the address of dest is lesser than the arddress of src, call "ft_memcpy"
with dest, src and n.
Otherwise, copy by starting from the end to avoid the overlap.
Return dest.
*/
