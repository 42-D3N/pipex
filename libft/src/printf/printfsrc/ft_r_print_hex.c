/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_print_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:26:14 by tle-pape          #+#    #+#             */
/*   Updated: 2024/11/11 10:53:07 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static char	puthex(int hex, char format)
{
	if (hex > 9)
	{
		if (format == 'x')
			hex = hex - 10 + 'a';
		else if (format == 'X')
			hex = hex - 10 + 'A';
		return (hex);
	}
	else
	{
		hex = hex + '0';
		return (hex);
	}
	return (0);
}

static int	nblen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

int	ft_r_print_hex(unsigned int nbr, char format)
{
	int		i;
	int		hex;
	int		len;
	char	*str;

	i = 0;
	len = nblen(nbr);
	str = malloc(sizeof(char *) * len + 1);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		hex = (nbr % 16);
		str[len] = puthex(hex, format);
		nbr /= 16;
		len--;
		i++;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (i);
}
