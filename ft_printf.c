/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:56:59 by hualhash          #+#    #+#             */
/*   Updated: 2022/12/13 23:25:03 by hualhash         ###   ########.fr       */
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
	else if (s == 'x' || s == 'X')
		x += ft_hex_base(va_arg(args, unsigned int), s);
	else if (s == 'p')
	{
		x += write(1, "0x", 2);
		x += ft_hex_base(va_arg(args, unsigned long), 'x');
	}
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
// 	p = "5";
	// ft_printf("fake: NULL %s NULL \n", NULL);
	// printf("real: NULL %s NULL \n", NULL);
	// ft_printf("Me testing char: %c\n", c);
	// printf("Real testing char: %c\n", c);
	// ft_printf("Me testing decimal: %d\n", d);
	// printf("Real testing decimal: %d\n", d);
	// ft_printf("Me testing integar: %d\n", i);
	// printf("Real testing integar: %d\n", i);
	// ft_printf("Me testing{%%} %%\n");
	// printf("Real testing{%%} %%\n");
	// ft_printf("Me testing unsigned int %u\n", u);
	// printf("Real testing unsigned int %u\n", u);
	// ft_printf("Me testing Hex(x) %x\n", x);
	// printf("Real testing Hex(x) %x\n", x);
	// ft_printf("Me testing Hex(X) %X\n", -9223372036854775808UL);
	// printf("Real testing Hex(X) %X\n", -9223372036854775808UL);
	// printf("Real address = %p\n", -9223372036854775808UL);
	// ft_printf("fake add: %p\n", -9223372036854775808UL);
	// // // printf("%p\n", p);
	// ft_printf("%p", p);
// }
// int main()
// {
// 	long i,u;

// 	i = 0;
// 	u = 0;
// 	i = ft_printf("X: %X\n", 4785);
// 	u = printf("X: %X\n", 4785);
	
// 	printf("i = %ld\nu = %ld\n", i, u);

// 	long l,v;

// 	l = 0;
// 	v = 0;
// 	l = ft_printf("x: %x\n", 4785);
// 	v = printf("x: %x\n", 4785);
	
// 	printf("l = %ld\nv = %ld", l, v);
// }

// int	ft_check(char c, va_list arg)
// {
// 	int	p;

// 	p = 0;
// 	if (c == 'c')
// 		p += ft_putchar(va_arg(arg, int));
// 	else if (c == 's')
// 		p += ft_putstr(va_arg(arg, char *));
// 	else if (c == 'd' || c == 'i')
// 		p += ft_putnbr(va_arg(arg, int));
// 	else if (c == 'u')
// 		p += ft_u(va_arg(arg, unsigned int));
// 	else if (c == 'x' || c == 'X')
// 		p += ft_hex_base(va_arg(arg, unsigned int), c);
// 	else if (c == 'p')
// 	{
// 		p += write(1, "0x", 2);
// 		p += ft_hex_base(va_arg(arg, unsigned long), 'x');
// 	}
// 	else if (c == '%')
// 		p += ft_putchar('%');
// 	else
// 		return (ft_putchar(c));
// 	return (p);
// }

// #include<stdio.h>
// #include<printf.h>
// #include<unistd.h>

// int	main(void)
// {
// 	int				i;
// 	int				d;
// 	unsigned int	l;
// 	unsigned int	kira;
// 	void			*p;

// 	p = (int *)0;
// 	i = 0;
// 	d = -0;
// 	kira = 4294967295;
// 	l = 0;
// 	printf("Original = :%%: :%c: [%d] [%i] :%p:\n", 'a', d, i, p);
// 	ft_printf("Mine     = :%%: :%c: [%d] [%i] :%p:\n", 'a', d, i, p);
// 	write(1, "\n\n", 2);
// 	printf("Original = u:[%u] x:[%x] X:[%X] s:[%s]\n", kira, l, l,
// 		"Uciha Jafar");
// 	ft_printf("Mine     = u:[%u] x:[%x] X:[%X] s:[%s]\n", kira, l, l,
// 		"Uciha Jafar");
// ft_printf("Me testing Hex(X) %X\n", -9223372036854775808UL);
// 	printf("Real testing Hex(X) %X\n", -9223372036854775808UL);
// 	printf("Real address = %p\n", -9223372036854775808UL);
// 	ft_printf("fake add: %p\n", -9223372036854775808UL);
// }