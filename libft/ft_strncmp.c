/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:12:43 by vsanz-ar          #+#    #+#             */
/*   Updated: 2022/12/28 12:49:59 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (size_t)i < n)
	{
		a = ((unsigned char *)s1)[i];
		b = ((unsigned char *)s2)[i];
		if (s1[i] != '\0' && s2[i] == '\0')
			return (1);
		else if (s1[i] == '\0' && s2[i] != '\0')
			return (-1);
		else if (a != b)
			return (a - b);
		i++;
	}
	return (0);
}
