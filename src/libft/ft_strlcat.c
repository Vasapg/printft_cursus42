/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:13:47 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/24 15:01:46 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	length;
	unsigned int	length2;

	if (dstsize == 0)
		return (ft_strlen(src));
	j = 0;
	i = ft_strlen(dst);
	length = ft_strlen(dst);
	length2 = ft_strlen(src);
	if (dstsize <= length)
	{
		length = ft_strlen(src);
		return (dstsize + length);
	}
	while (src[j] != '\0' && j < dstsize - 1 - length)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return ((size_t)(length2 + length));
}
