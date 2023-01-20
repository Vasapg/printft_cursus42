/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:04:27 by vsanz-ar          #+#    #+#             */
/*   Updated: 2022/12/28 12:45:28 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < (int)len)
	{
		if (src > dst)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		else
			((unsigned char *)dst)[len - i - 1]
				= ((unsigned char *)src)[len - i - 1];
		i++;
	}
	return (dst);
}
