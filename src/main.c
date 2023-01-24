/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:56:07 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/24 12:10:50 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"
#include<stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 1)
		return (-1);
	char a = 'a';
	int c = 1;
	int dia =123344;
	ft_printf("hola que tal%c hoy es dia %x", a, dia);
	printf("\n");
	printf("hola que tal%c hoy es dia %x", a, dia);
	printf("\n");
	int *b = &c;
	int nb1;
	int nb2;
	nb1 = ft_printf("el valor del puntero en hexadecimal sera: %p\n", b);
	nb2 = printf("el valor del puntero en hexadecimal sera: %p\n", b);
	printf("caracteres leidos por ft_printf:%i\ny por printf: %i\n", nb1, nb2);
	return (1);
}
