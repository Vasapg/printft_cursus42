/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:57:52 by vsanz-ar          #+#    #+#             */
/*   Updated: 2022/12/28 14:24:16 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	fill_string(char const *s1, char *s2, int k, int i)
{
	int	j;

	j = 0;
	while (i < (int)ft_strlen(s1) - k)
		s2[j++] = s1[i++];
	s2[j] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 1;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (j == 1 && i < (int)ft_strlen(s1))
	{
		if (NULL != ft_strchr(set, (int)s1[i]))
			i++;
		else if (NULL != ft_strchr(set, (int)s1[(int)ft_strlen(s1) - k - 1]))
			k++;
		else
			j = 0;
	}
	s2 = malloc(sizeof(const char) * (ft_strlen(s1) + 1 - i - k));
	if (s2 == NULL)
		return (NULL);
	fill_string(s1, s2, k, i);
	return (s2);
}
