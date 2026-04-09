/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:48:04 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/29 12:32:27 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len != 0)
		while (s[i + start] && i < len)
			i++;
	str = (char *) malloc (i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
Check if len is lesser than the total size of s. If no, set len to the size of s
Check if start is lesser than the total size of s.
If no, return an empty string created with "ft_strdup".
Check if len is not equal to 0.
If len is greater than 0, icrement i to get the lengh of the new str.
Malloc str and if malloc fail, return NULL.
Reset i and copy in str the substring to copy and add \0 at the end.
Return str.
*/
