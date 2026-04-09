/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:50:22 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 11:40:50 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i])
		i++;
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
Get the lengh of the string to create, with the first while.
Allocate str with the lengh + 1.
If the malloc fail, return NULL.
Reset i to 0 and copy src in the new string.
Add the \0 at the end of the string and return str.
*/
