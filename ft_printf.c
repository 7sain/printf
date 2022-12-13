/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:56:59 by hualhash          #+#    #+#             */
/*   Updated: 2022/12/13 13:12:14 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			i;
	int			x;
	va_list		args;

	va_start(args, format);
	i = 0;
	x = 0;
	while (format[i] != '\0')
	{
		// if (format[i] == ' ' || format[i] != '%')
		// 	x += ft_putchar(format[i]);
		if (format[i] == '%')
		{
			i++;
			x += checker(format[i], args);
			i++;
		}
		else
			x += write(1, &format[i++], 1);
	}
	va_end(args);
	return (x);
}

int	checker(char s, va_list args)
{
	int	x;

	x = 0;
	if (s == 'c')
		x += ft_putchar(va_arg(args, int));
	else if (s == 's')
		x += ft_putstr(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		x += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		x += ft_uputnbr(va_arg(args, int));
	else if (s == 'x')
		ft_printhex_small(va_arg(args, int), &x);
	else if (s == 'X')
		x += ft_printhex_upper(va_arg(args, int), &x);
	else if (s == 'p')
		x += ft_pp(va_arg(args, unsigned long), &x);
	else if (s == '%')
		x += ft_putchar('%');
	else if (s == '\n')
		write(1, "\n", 1);
	return (x);
}

// int	main(void)
// {
// 	char			*s;
// 	char			c;
// 	int				d;
// 	int				i;
// 	unsigned int	u;
// 	int				x;
// 	int				X;
// 	char			*p;

// 	s = "PASSED";
// 	c = 'A';
// 	d = 100;
// 	i = 10;
// 	u = -1;
// 	x = 999;
// 	X = 999;
// 	p = "hihihi";
// 	ft_printf("fake: NULL %s NULL \n", NULL);
// 	printf("real: NULL %s NULL \n", NULL);
// 	ft_printf("Me testing char: %c\n", c);
// 	printf("Real testing char: %c\n", c);
// 	ft_printf("Me testing decimal: %d\n", d);
// 	printf("Real testing decimal: %d\n", d);
// 	ft_printf("Me testing integar: %d\n", i);
// 	printf("Real testing integar: %d\n", i);
// 	ft_printf("Me testing{%%} %%\n");
// 	printf("Real testing{%%} %%\n");
// 	ft_printf("Me testing unsigned int %u\n", u);
// 	printf("Real testing unsigned int %u\n", u);
// 	ft_printf("Me testing Hex(x) %x\n", x);
// 	printf("Real testing Hex(x) %x\n", x);
// 	ft_printf("Me testing Hex(X) %X\n", X);
// 	printf("Real testing Hex(X) %X\n", X);
// 	printf("Real address = %p\n", p);
// 	ft_printf("fake add: %p\n", p);
// }
int main()
{
	int i,u;

	i = 0;
	u = 0;
	i = ft_printf("X: %X\n", -1);
	u = printf("X: %X\n", -1);
	
	printf("i = %d\nu = %d\n", i, u);

	int l,v;

	l = 0;
	v = 0;
	l = ft_printf("x: %x\n", -1);
	v = printf("x: %x\n", -1);
	
	printf("l = %d\nv = %d", l, v);
}