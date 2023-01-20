/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:16:15 by vsanz-ar          #+#    #+#             */
/*   Updated: 2022/12/28 14:17:24 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size2;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	s3 = malloc((size1 + size2 + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	size2 = 0;
	size1 = 0;
	while (s1[size1] != '\0')
	{
		s3[size1] = s1[size1];
		size1++;
	}
	while (s2[size2] != '\0')
		s3[size1++] = s2[size2++];
	s3[size1] = '\0';
	return (s3);
}
