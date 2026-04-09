/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapo <rapo@rapo.rapo>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:35:54 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 12:47:11 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	final_len(char const *s1, char const *set)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(s1);
	while (check_set(s1[i], set))
		i++;
	if (i == n)
		return (0);
	while (check_set(s1[n - 1], set))
		n--;
	return (n - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (!s1[i])
		return (ft_strdup(""));
	else if (!set[i])
		return (ft_strdup((char *) s1));
	len = final_len(s1, set);
	while (check_set(s1[i], set))
		i++;
	str = ft_substr(s1, i, len);
	if (!str)
		return (NULL);
	return (str);
}
/*
----------------------------------CHECK_SET-------------------------------------
This function check every character in set with the character given.

----------------------------------FINAL_LEN-------------------------------------
This function calculate the totel lengh of the final string.

----------------------------------FT_STRTRIM------------------------------------
This function will removed all characters which corresponds to set at the start
and the end of the string and malloc a new string.
Check if s1 or set is not empty.
If s1 is empty, return an empty string with "ft_strdup"
If set is empty, return a copy of the original string with "ft_strdup"
Calculate the final lengh with "final_len".
Check all characters first with "check_set" and use "ft_substr" to create str.
Str start to i and end at len.
Return str.
*/
