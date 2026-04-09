/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:41:16 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 11:09:25 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb == -2147483648)
	{
		write(fd, "2", 1);
		ft_putnbr_fd(147483648, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		i = nb + 48;
		write(fd, &i, 1);
	}
}
/*
Use the putnbr function by replacing the output of write function by the file.
*/
