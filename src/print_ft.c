/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:45:46 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/20 18:18:25 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	convert(char c, va_list args)
{
	//TODO: IMPLEMENTAR FUNCTION PUNTERO, IMPLEMENTAR UNSIGNED INT
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (c == '%')
		ft_putchar_fd(c, 1);
	if (c == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	if (c == 'x')
		ft_putstr_fd(ft_itoh(va_arg(args, int), 1), 1);
	if (c == 'X')
		ft_putstr_fd(ft_itoh(va_arg(args, int), 0), 1);
	return (1);
}

int	arg_length(va_list arg, char c)
{
	if (c == '%' || c == 'c')
		return (1);
	if (c == 'd' || c== 'i')
		return (ft_strlen(ft_itoa(va_arg(arg, int))));
	if (c == 's')
		return (ft_strlen(va_arg(arg, char *)));
	if (c == 'x' || c == 'X')
		return (ft_strlen(ft_itoh(va_arg(arg, int), 1)));
	else
		return (0);
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
		else if (ft_strchr("cspdiuxX%", format[++i])!=NULL)
		{
			//TODO: CALL LENGHT FUNCTION FOR VA_COPY
			convert(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i - 1], 1);
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (1);
}
