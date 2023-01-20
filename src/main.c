/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:56:07 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/01/20 15:56:11 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"
#include<stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 1)
		return (-1);
	char *a = " como estas";
	int dia = 123;
	ft_printf("hola que tal%s hoy es dia %d", a, dia);
	printf("\n");
	printf("hola que tal%s hoy es dia %x", a, dia);
	return (1);
}
