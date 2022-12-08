/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:26:44 by hualhash          #+#    #+#             */
/*   Updated: 2022/12/08 21:39:59 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
			i += ft_putnbr(nb / 10);
			i += ft_putnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}
