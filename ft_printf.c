/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:56:59 by hualhash          #+#    #+#             */
/*   Updated: 2022/12/08 22:07:50 by hualhash         ###   ########.fr       */
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
		if (format[i] == ' ' || format[i] != '%')
			x += ft_putchar(format[i]);
		else if (format[i] == '%')
		{
			i++;
			x += checker(format[i], args);
		}
		// else
		// 	x += ft_putchar(va_arg(args, int));
		i++;
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
	else if (s == '%')
		x += ft_putchar('%');
	else if (s == '\n')
		write(1, "\n", 1);
	return (x);
}

int	main(void)
{
	char			*s;
	char			c;
	int				d;
	int				i;
	unsigned int	u;

	s = "PASSED";
	c = 'A';
	d = 100;
	i = 10;
	u = 1;
	ft_printf("Me testing string: %s\n", s);
	printf("Real testing string: %s\n", s);
	ft_printf("Me testing char: %c\n", c);
	printf("Real testing char: %c\n", c);
	ft_printf("Me testing decimal: %d\n", d);
	printf("Real testing decimal: %d\n", d);
	ft_printf("Me testing integar: %d\n", i);
	printf("Real testing integar: %d\n", i);
	ft_printf("Me testing{%%} %%\n");
	printf("Real testing{%%} %%\n");
	ft_printf("Me testing unsigned int %u\n", u);
	printf("Real testing unsigned int %u\n", u);
}
