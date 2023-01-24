/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:54:18 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/24 12:37:42 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

char	*ft_itoh(unsigned long int nb, int mode)
{
	char					*res;
	int						i;
	unsigned long int		aux;
	char const				*hex;

	if (nb == 0)
		return ("0");
	hex = "0123456789ABCDEF";
	aux = nb;
	i = 0;
	while (aux != 0)
	{
		aux = aux / 16;
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
		nb = nb / 16;
	}
	return (res);
}

char	*ft_itou(unsigned int n)
{
	char			*res;
	int				i;
	unsigned int	aux;

	i = 0;
	aux = n;
	res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	res[i] = '\0';
	i--;
	while (n != 0)
	{
		res[i--] = (char)(n % 10) + 48;
		n = n / 10;
	}
	return (res);
}
