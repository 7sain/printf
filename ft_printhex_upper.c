/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:32:35 by hualhash          #+#    #+#             */
/*   Updated: 2022/12/11 21:13:45 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_upper(unsigned int x, int *count)
{
	char s[] = "0123456789ABCDEF";
	if(x >= 16)
		ft_printhex_upper(x / 16, count);
	*count += write(1, &s[x % 16], 1);
	// char	count;
	// int		t;
	// if (x >= 16)
	// {
	// 	ft_printhex_upper(x / 16);
	// 	ft_printhex_upper(x % 16);
	// }
	// else if (x <= 9)
	// {
	// 	ft_putchar(x + '0');
	// }
	// else
	// {
	// 	ft_putchar (x - 10 + 'A');
	// }
	// t = strlen(&count);
	return (1);
}
