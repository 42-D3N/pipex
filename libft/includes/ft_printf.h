/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:12:21 by tle-pape          #+#    #+#             */
/*   Updated: 2024/11/11 09:01:30 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int	ft_printf(const char *str, ...);
int	ft_checkformat(va_list flag, const char format);
int	ft_r_print_hex(unsigned int nbr, char format);
int	ft_r_putnbr(int nbr);
int	ft_r_putptr(unsigned long long ptr);
int	ft_r_putstr(char *str);
int	ft_r_unsigned_dec(unsigned int nbr);

#endif
