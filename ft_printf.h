/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:59:04 by hualhash          #+#    #+#             */
/*   Updated: 2022/12/13 23:24:11 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	checker(char s, va_list args);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_uputnbr(unsigned int nb);
int	ft_hex_base(unsigned long nb, int flag);
#endif