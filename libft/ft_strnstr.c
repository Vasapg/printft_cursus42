/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:45:41 by vsanz-ar          #+#    #+#             */
/*   Updated: 2022/12/28 12:50:25 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((haystack == NULL || needle == NULL) && len == 0)
		return (NULL);
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && (size_t)i < len)
	{
		if (haystack[i] == needle[j])
		{
			while ((size_t)(i + j) < len && haystack[i + j] == needle[j])
			{
				if (needle[++j] == '\0')
					return ((char *)haystack + i);
				if (haystack[i + j] == '\0')
					return (NULL);
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
