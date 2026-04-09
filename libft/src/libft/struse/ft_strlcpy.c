/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:56:46 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 12:03:04 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	tsize;

	i = 0;
	tsize = ft_strlen(src);
	if (size == 0)
		return (tsize);
	else if (tsize == 0)
	{
		dst[i] = '\0';
		return (tsize);
	}
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (tsize);
}
/*
Get the lengh of src in tsize.
If size is equal to 0, return tsize.
Otherwise, if tsize is equal to 0, that mean the string is empty so we add \0
to dst and return tsize.
Otherwise, add src to dest until the end of src and until the function don't
reach size - 1.
Add \0 at the end and return tsize.
*/
