/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:25:25 by hualhash          #+#    #+#             */
/*   Updated: 2022/12/13 20:58:59 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pp(unsigned long x, int *r)
{
	int		i;

	i = 0;
	write(1, "0x", 2);
	i = ft_printhex_pointer(x, r);
	return (i + 2);
}

// int main(void)
// {
// 	char *a;
// 	int *h;
	
// 	// a = ;
// 	ft_pp(-9223372036854775808UL, );
// 	printf("\norignal: %p", a);
	
// }