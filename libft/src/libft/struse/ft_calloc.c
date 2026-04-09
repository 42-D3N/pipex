/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:01:40 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 10:13:26 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;

	if (nmemb * size > 2147483647)
		return (NULL);
	mem = (unsigned char *) malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
/*
The first IF check in case of overflow.
The second IF return NULL if malloc failed.
Call "ft_bzero" to fill mem with 0.
*/
