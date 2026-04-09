/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_unsigned_dec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:26:14 by tle-pape          #+#    #+#             */
/*   Updated: 2024/11/11 10:00:46 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static int	nblen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int	ft_r_unsigned_dec(unsigned int nbr)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = nblen(nbr);
	str = malloc(sizeof (char *) * len + 1);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (nbr % 10 + '0');
		nbr /= 10;
		len--;
		i++;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (i);
}
