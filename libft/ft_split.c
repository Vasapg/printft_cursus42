/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:52:46 by vsanz-ar          #+#    #+#             */
/*   Updated: 2022/12/28 14:24:39 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	**free_matrix(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		res[i] = NULL;
		i--;
	}
	free(res);
	res = NULL;
	return (NULL);
}

int	n_of_strings(char const *s, char del)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != del)
		{
			res++;
			while (s[i] != del && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (res);
}

int	fill_matrix(char const *s, char del, char **res, int j)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	n = 0;
	while (s[i] == del && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (i);
	str = (char *)&s[i];
	while (s[i] != del && s[i] != '\0')
	{
		n++;
		i++;
	}
	res[j] = malloc(sizeof(char) * (n + 1));
	if (res[j] == NULL)
	{
		free_matrix(res, j);
		return (-1);
	}
	res[j][n] = '\0';
	ft_memcpy(res[j], str, n);
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**res;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	n = n_of_strings(s, c);
	res = malloc(sizeof(char *) * (n + 1));
	if (res == NULL)
		return (NULL);
	res[n] = (void *) 0;
	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		i += fill_matrix(&s[i], c, res, j);
		if (i == -1)
			return (NULL);
		j++;
	}
	return (res);
}
