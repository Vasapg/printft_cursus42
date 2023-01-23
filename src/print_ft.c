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
		ft_putstr_fd(itoh(va_arg(args, int), 1), 1);
	if (c == 'X')
		ft_putstr_fd(itoh(va_arg(args, int), 0), 1);
	return (1);
}

char	*itoh(int nb, int mode)
{
	char 	*res;
	int		i;
	int 	aux;
	char	*hex;

	hex  = "0123456789ABCDEF";
	aux = nb;
	i = 0;
	while (aux != 0)
	{
		aux  = aux/16;
		i++;
	}
	res = malloc(sizeof(char) * (i + 1));
	res[i + 1] = '\0';
	i--;
	while (nb != 0)
	{
		if (nb % 16 > 9 && mode)
			res[i--] = ft_tolower(hex[nb % 16]);
		else
			res[i--] = hex[nb % 16];
		nb  = nb / 16;
	}	
	return (res);
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
			convert(format[i], args);
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
