/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:01:27 by vsanz-ar          #+#    #+#             */
/*   Updated: 2022/12/28 14:40:54 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	aux_fill(const char *s, int start, size_t len, char *res)
{
	int	i;
	int	j;

	i = 0;
	j = start;
	while (s[j] != '\0' && (size_t)i < len)
	{
		res[i] = s[j];
		j++;
		i++;
	}
	res[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	int				i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		res = malloc((ft_strlen(s) + 1) * sizeof(char));
	else
		res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		res[0] = '\0';
		return (res);
	}
	i = 0;
	j = start;
	aux_fill(s, start, len, res);
	return (res);
}
