/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:09:30 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/20 18:09:38 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../libft/libft.h"
#include<stdarg.h>

int		ft_printf(char const *, ...);
int		convert(char c, va_list args);
char	*ft_itoh(int nb, int mode);
int		arg_length(va_list arg, char c);
