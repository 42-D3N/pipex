/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:50:15 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 11:07:18 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (n > 0)
	{
		str[i] = c;
		i++;
		n--;
	}
	return (str);
}
/*
Cast in unsigned char * s in a new str.
Until n is greater than 0, replace the actual byte with c.
Return str.
*/
