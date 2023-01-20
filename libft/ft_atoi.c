/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:49:42 by vsanz-ar          #+#    #+#             */
/*   Updated: 2022/12/28 12:34:01 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_aux(const char *str, int i)
{
	int	res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{	
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		res = ft_atoi_aux(str, i);
		return (res * sign);
	}
	else
		return (0);
}
