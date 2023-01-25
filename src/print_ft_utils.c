/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:54:18 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/24 15:49:56 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"
#include<stdio.h>

int	count_numbers(unsigned long int nb, int base)
{
	int	i;

	if (nb <= 0)
		return (1);
	i = 0;
	while (nb != 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char	*ft_itoh(unsigned long int nb, int mode)
{
	char		*res;
	int			i;

	i = count_numbers(nb, 16);
	if (mode == 1 || mode == 0)
		i = count_numbers((unsigned int)nb, 16);
	res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	if (nb <= 0)
	{
		res[0] = '0';
		res[1] = '\0';
	}
	res[i + 1] = '\0';
	i--;
	while (nb != 0)
	{
		if (nb % 16 > 9 && (mode == 1 || mode == 2))
			res[i--] = "0123456789abcdef"[nb % 16];
		else
			res[i--] = "0123456789ABCDEF"[nb % 16];
		nb = nb / 16;
	}
	return (res);
}

char	*ft_utoa(unsigned int n)
{
	char	*res;
	int		i;

	i = count_numbers(n, 10);
	res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		i--;
	}
	res[i + 1] = '\0';
	i--;
	while (n != 0)
	{
		res[i--] = (char)(n % 10) + 48;
		n = n / 10;
	}
	return (res);
}
