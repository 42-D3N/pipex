/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:51:20 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 12:10:02 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen((char *) s);
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
Get the lengh of s and malloc str with the size of s.
If malloc fail, return NULL.
While the function don't reach the end of s, apply f on each character and add
it to str. Add \0 at the end of str and return str.
*/
