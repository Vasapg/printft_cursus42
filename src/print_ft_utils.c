#include"libftprintf.h"
char	*itoh(int nb, int mode)
{
	char 	*res;
	int		i;
	int 	aux;
	char	*hex;

	hex  = "0123456789ABCDEF";
	aux = nb;
	i = 0;
	while (aux != 0)
	{
		aux  = aux/16;
		i++;
	}
	res = malloc(sizeof(char) * (i + 1));
	res[i + 1] = '\0';
	i--;
	while (nb != 0)
	{
		if (nb % 16 > 9 && mode)
			res[i--] = ft_tolower(hex[nb % 16]);
		else
			res[i--] = hex[nb % 16];
		nb  = nb / 16;
	}	
	return (res);
}
