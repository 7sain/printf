/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_small.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:12:02 by hualhash          #+#    #+#             */
/*   Updated: 2022/12/11 21:25:10 by hualhash         ###   ########.fr       */
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
	return (1);
}

int	ft_printhex_pointer(unsigned long x, int *r)
{
	if (x >= 16)
	{
		ft_printhex_small(x / 16, r);
		ft_printhex_small(x % 16, r);
	}
	else if (x <= 9)
	{
		ft_putchar(x + '0');
	}
	else
		ft_putchar (x - 10 + 'a');
	return (1);
}
