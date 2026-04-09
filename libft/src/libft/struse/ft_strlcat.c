/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:58:48 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 11:50:48 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	tsize;

	i = 0;
	j = 0;
	tsize = (size_t) ft_strlen(dst) + (size_t) ft_strlen(src);
	if ((size_t) ft_strlen(dst) >= size)
		return ((size_t) ft_strlen(src) + size);
	while (dst[i])
		i++;
	while (src[j] && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (tsize);
}
/*
Get the total size of the new string by using "ft_strlen" on the 2 strings to 
calculate the final lengh of the string.
Check if the dest is able to contain src until the size.
If no, return the lengh of src + size.
Get the end of dest in i.
In the second loop, add src to dest.
Add the \0 at the end of dest and return tsize.
*/
