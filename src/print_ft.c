/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:45:46 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/20 15:58:41 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	convert(char c, va_list args)
{
	int	error;

	error = 0;
	if (c == 'c')
		ft_putchar_fd((char)va_arg(args, char*), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(args, char*), 1);
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (c == '%')
		ft_putchar_fd(c, 1);
	if (c == 'u')
		return 1;
	if (c == 'x')
		return 1;
	else
		error = 1;
	return (error);
}

int ft_printf(char const * format, ...)
{
	va_list args;
	int	i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		else
		{
			i++;
			convert(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (1);
}


