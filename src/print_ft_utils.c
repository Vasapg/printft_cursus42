/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:54:18 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/24 11:54:30 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

char	*ft_itoh(unsigned long int nb, int mode)
{
	char					*res;
	int						i;
	unsigned long int		aux;
	char const				*hex;

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
