/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:09:30 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/26 12:48:45 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(char const *format, ...);
char	*ft_itop(unsigned long int nb);
char	*ft_itoh(unsigned int nb, int mode);
char	*ft_utoa(unsigned int nb);
int		print_and_free(char *str, char c);
int		argtos(char c, va_list args);
int		count_numbers(unsigned long int nb, int base);
#endif
