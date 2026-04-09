/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:53:02 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 12:22:38 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	s;
	size_t	t;
	char	*str;

	s = 0;
	t = 0;
	str = (char *) big;
	if (!little[t])
		return (str);
	if (len == 0)
		return (0);
	while (big[s] && t <= len)
	{
		while (str[s + t] == little[t] && big[s + t] && s + t < len)
			t++;
		if (!little[t])
			return (str + s);
		s++;
		t = 0;
	}
	return (0);
}
/*
Cast in char * big in str. check if little is not empty, otherwise, return str.
Check if len is greater than 0, if no, return 0.
As long as big not reached the end, and t is lesser or equal to len, loop.
- Compare the current character of str and the character of little.
- Check if big not reach to the end and check if s + t is lesser than len.
- If little reach to the end, return str+s to return the start of little in big.
Otherwise, increment s and reset t.
Return 0 if nothing has been found.
*/
