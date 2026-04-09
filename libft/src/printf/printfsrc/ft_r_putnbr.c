/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:06:10 by tle-pape          #+#    #+#             */
/*   Updated: 2024/11/11 10:34:14 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	ft_r_putnbr(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	len = ft_r_putstr(str);
	free(str);
	return (len);
}
