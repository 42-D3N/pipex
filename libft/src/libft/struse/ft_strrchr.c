/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:07:41 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 12:29:19 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*adress;
	int		i;

	adress = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c % 128)
			adress = (char *)s + i;
		i++;
	}
	if (c % 128 == 0)
		adress = (char *)s + i;
	return (adress);
}
/*
As long as there is characters in s, loop.
If the current character is equal to c (% 128), set address to the current char.
If nothing is found and the character c is 0, set address to the end of s.
*/
