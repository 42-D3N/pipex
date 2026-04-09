/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:08:27 by tle-pape          #+#    #+#             */
/*   Updated: 2024/11/11 10:17:18 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	flag;

	i = 0;
	len = 0;
	va_start(flag, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_checkformat(flag, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(flag);
	return (len);
}
