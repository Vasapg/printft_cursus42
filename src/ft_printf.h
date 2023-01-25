/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:09:30 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/24 15:40:58 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(char const *format, ...);
void	convert(char c, va_list args);
char	*ft_itoh(unsigned long int nb, int mode);
char	*ft_utoa(unsigned int nb);
int		arg_length(va_list arg, char c);
#endif
