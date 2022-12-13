/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_small.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:12:02 by hualhash          #+#    #+#             */
/*   Updated: 2022/12/13 21:05:57 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_small(unsigned int x, int *count)
{
	char s[] = "0123456789abcdef";
	if(x >= 16)
		ft_printhex_small(x / 16, count);
	*count += write(1, &s[x % 16], 1);
	
	// if (x >= 16)
	// {
	// 	*count += ft_printhex_small(x / 16, count);
	// 	*count += ft_printhex_small(x % 16, count);
	// }
	// else if (x <= 9)
	// {
	// 	ft_putchar(x + '0');
	// }
	// else
	// 	ft_putchar (x - 10 + 'a');
	return (0);
}

int	ft_printhex_pointer(unsigned long x, int *count)
{
	char s[] = "0123456789abcdef";
	if(x >= 16)
		ft_printhex_small(x / 16, count);
	*count += write(1, &s[x % 16], 1);
	// if (x >= 16)
	// {
	// 	ft_printhex_small(x / 16, r);
	// 	ft_printhex_small(x % 16, r);
	// }
	// else if (x <= 9)
	// {
	// 	ft_putchar(x + '0');
	// }
	// else
	// 	ft_putchar (x - 10 + 'a');
	return (0);
}
int	ft_hex_base(unsigned long nb, int flag)
{
	int		c;
	char	*base;

	c = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (flag == 'x')
		base = "0123456789abcdef";
	if (flag == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		c += ft_hex_base(nb / 16, flag);
		c += ft_hex_base(nb % 16, flag);
	}
	else
		c += ft_putchar(base[nb]);
	return (c);
}
