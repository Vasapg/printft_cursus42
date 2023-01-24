/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:33:03 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/24 12:32:32 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	number_of_digits(int numb)
{
	int	i;

	i = 0;
	if (numb <= 0)
		i++;
	while (numb != 0)
	{
		i++;
		numb = numb / 10;
	}
	return (i);
}

int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = number_of_digits(n);
	res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	res[i] = '\0';
	i--;
	while (n != 0)
	{
		res[i--] = (char)abs((n % 10)) + 48;
		n = n / 10;
	}
	return (res);
}
