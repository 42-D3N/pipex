/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:12:56 by tle-pape          #+#    #+#             */
/*   Updated: 2024/11/11 10:11:43 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_r_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_checkformat(va_list flag, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_r_putchar(va_arg(flag, int));
	else if (format == 's')
		len += ft_r_putstr(va_arg(flag, char *));
	else if (format == 'p')
		len += ft_r_putptr(va_arg(flag, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_r_putnbr(va_arg(flag, int));
	else if (format == 'u')
		len += ft_r_unsigned_dec(va_arg(flag, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_r_print_hex(va_arg(flag, unsigned int), format);
	else if (format == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}
