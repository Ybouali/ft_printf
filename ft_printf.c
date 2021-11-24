/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 05:31:10 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/24 17:58:55 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_if_steatment(const char format, va_list arg_ptr)
{
	int	n;

	n = 0;
	if (format == 'c')
		n = ft_putchar(va_arg(arg_ptr, int));
	else if (format == 's')
		n = ft_putstr(va_arg(arg_ptr, char *));
	else if (format == 'd' || format == 'i')
		n = ft_putnbr(va_arg(arg_ptr, int));
	else if (format == 'x')
		n = ft_putnbr_base(va_arg(arg_ptr, unsigned int), "0123456789abcdef");
	else if (format == 'u')
		n = ft_putnbr_base(va_arg(arg_ptr, unsigned int), "0123456789");
	else if (format == 'X')
		n = ft_putnbr_base(va_arg(arg_ptr, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
	{
		write (1, "0x", 2);
		n += 2;
		n += ft_putnbr_base(va_arg(arg_ptr, unsigned long), "0123456789abcdef");
	}
	return (n);
}

int	ft_check(char c)
{
	char	*test;

	test = "cdxXiusp";
	while (*test)
	{
		if (*test == c)
			return (1);
		test++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		argptr;
	int			index;
	int			n;

	n = 0;
	va_start(argptr, format);
	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			index += 2;
			if (ft_check(format[index - 1]) == 1)
				n += ft_if_steatment(format[index - 1], argptr);
			else
				n += ft_putchar(format[index - 1]);
		}
		else
		{
			n += ft_putchar(format[index]);
			index++;
		}
	}
	va_end(argptr);
	return (n);
}
