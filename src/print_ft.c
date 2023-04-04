/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:45:46 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/04/04 13:28:19 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

// retrieve an argument as a string, no matter its type
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
		str = va_arg(args, char *);
	if (c == '%')
		str = ft_strdup("%");
	if (c == 'p')
		str = ft_itop(va_arg(args, unsigned long int));
	if (c == 'd' || c == 'i')
		str = ft_itoa(va_arg(args, int));
	if (c == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	if (c == 'x')
		str = ft_itoh(va_arg(args, int), 1);
	if (c == 'X')
		str = ft_itoh(va_arg(args, int), 0);
	return (print_and_free(str, c));
}

// print and free a str, taking in account pointer format
int	print_and_free(char *str, char c)
{
	int	length;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	else
		ft_putstr_fd(str, 1);
	length = ft_strlen(str);
	if (c != 's')
		free(str);
	return (length);
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
		if (format[i] == '%' && format[i + 1]
			&& ft_strchr("cspdiuxX%", format[i + 1]) != NULL)
			length += argtos(format[++i], args);
		else if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}
