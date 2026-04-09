/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:26:01 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 12:59:36 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	diff;
	unsigned int	i;
	unsigned char	c1;
	unsigned char	c2;

	diff = 0;
	i = 0;
	while ((s1[i] || s2[i]) && diff == 0 && n > 0)
	{
		c1 = (unsigned char) s1[i];
		c2 = (unsigned char) s2[i];
		if (c1 > c2 || c1 < c2)
			return (diff = c1 - c2);
		i++;
		n--;
	}
	return (0);
}
/*
Stay in the loop if s1 and s2 still have character in.
Compare c1 and c2 (as unsigned char) and if one of the 2 is lesser of greater,
return the difference. 
Otherwise, return 0.
*/
