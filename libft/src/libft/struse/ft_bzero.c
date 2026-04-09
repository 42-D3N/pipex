/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:31:04 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 10:07:13 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (n > 0)
	{
		str[i] = '\0';
		i++;
		n--;
	}
}
/*
Cast in unsigned char* to allow modification.
Change all octets of *s  with 0
*/
