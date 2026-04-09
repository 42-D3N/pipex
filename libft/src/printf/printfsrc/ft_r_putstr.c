/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:58:56 by tle-pape          #+#    #+#             */
/*   Updated: 2024/11/11 10:27:36 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	ft_r_putstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (i);
}
