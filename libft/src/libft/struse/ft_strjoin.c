/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:55 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 11:46:23 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
/*
This function get the total lengh of the 2 strings.
Malloc the new string with len and if malloc fail, return NULL.
Copy the first string in the new one.
Copy the second string in the new one.
Add \0 at the end and return the new string.
*/
