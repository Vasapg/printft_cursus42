/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:45:46 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/24 15:49:24 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"
#include<stdio.h>

void	convert(char c, va_list args)
{
	char	*str;

	str = NULL;
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		str = ft_itoh(va_arg(args, unsigned long int), 2);
	}
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (c == '%')
		ft_putchar_fd(c, 1);
	if (c == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	if (c == 'x')
		str = ft_itoh(va_arg(args, int), 1);
	if (c == 'X')
		str = ft_itoh(va_arg(args, int), 0);
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		free(str);
	}
}

// Function to retrieve an argument as a string, no matter its type
int	argtos(char c, va_list args)
{
	char	*str;

	str = NULL;
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	if (c == 's')
	{
		str = va_arg(args, char *);
		return (write(1, str, ft_strlen(str)));
	}
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		str = ft_itoh(va_arg(args, unsigned long int), 2);
	}
	if (c == 'd' || c == 'i')
		str = ft_itoa(va_arg(args, int));
	if (c == '%')
		str = ft_strdup("%");
	if (c == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	if (c == 'x')
		str = ft_itoh(va_arg(args, int), 1);
	if (c == 'X')
		str = ft_itoh(va_arg(args, int), 0);
	ft_putstr_fd(str, 1);
	free(str);
	return (1);
}

int	arg_length(va_list arg, char c)
{
	va_list	arg_aux;
	char	*str;
	int		res;

	str = NULL;
	va_copy(arg_aux, arg);
	if (c == '%' || c == 'c')
		return (1);
	if (c == 'd' || c == 'i')
		str = ft_itoa(va_arg(arg_aux, int));
	if (c == 's')
	{
		str = va_arg(arg_aux, char *);
		if (str != NULL)
			return (ft_strlen(str));
		return (ft_strlen("(null)"));
	}
	if (c == 'x' || c == 'X')
		str = (ft_itoh(va_arg(arg_aux, int), 1));
	if (c == 'p')
		str = ft_itoh(va_arg(arg_aux, unsigned long int), 2);
	if (c == 'u')
		str = ft_utoa(va_arg(arg_aux, unsigned int));
	res = ft_strlen(str);
	if (c == 'p')
		res += 2;
	free(str);
	va_end(arg_aux);
	return (res);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	length = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			length++;
		}
		else if (format[i] == '%'
			&& ft_strchr("cspdiuxX%", format[i + 1]) != NULL)
		{
			//length += arg_length(args, format[++i]);
			i++;
			argtos(format[i], args);
			
		}
		i++;
	}
	va_end(args);
	return (length);
}
