/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_putptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:28:49 by tle-pape          #+#    #+#             */
/*   Updated: 2024/11/11 10:58:28 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static int	ft_ptrlen(unsigned long long ptr)
{
	int	i;

	i = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

static int	ft_printptr(unsigned long long ptr)
{
	int					len;
	unsigned long long	t;

	t = 0;
	len = ft_ptrlen(ptr);
	if (ptr >= 16)
	{
		ft_printptr(ptr / 16);
		ft_printptr(ptr % 16);
	}
	else
	{
		if (ptr <= 10)
		{
			t = ptr + '0';
			write(1, &t, 1);
		}
		else
		{
			t = ptr - 10 + 'a';
			write(1, &t, 1);
		}
	}
	return (len);
}

int	ft_r_putptr(unsigned long long ptr)
{
	int	len;

	len = 2;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		len += ft_printptr(ptr);
	}
	return (len);
}
/*
int	main(void)
{
	char *str;
	char *sttr;
	char *sstr;
	char *strr;
	str = "Testest!";
	sttr = "bla";
	sstr = "bli";
	strr = "blu";
	printf("\n\nlen = %d\nprintf : %p\n", ft_r_putptr(str), str);
	ft_r_putptr(&*str);
	printf("\n\nlen = %d\nprintf : %p\n", ft_r_putptr(sttr), sttr);
	ft_r_putptr(&*sttr);
	printf("\n\nlen = %d\nprintf : %p\n", ft_r_putptr(sstr), sstr);
	ft_r_putptr(&*sstr);
}*/
