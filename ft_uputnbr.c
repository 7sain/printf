/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:57:18 by hualhash          #+#    #+#             */
/*   Updated: 2022/12/08 22:03:47 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uputnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
			i += ft_uputnbr(nb / 10);
			i += ft_uputnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + '0');
	return (i);
}
