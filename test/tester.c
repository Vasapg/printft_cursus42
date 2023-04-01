/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:22:22 by vsanz-ar          #+#    #+#             */
/*   Updated: 2023/04/01 16:03:34 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include <limits.h>
#include"../src/ft_printf.h"

void compare(int num1, int num2)
{
	if(num1 != num2)
		printf("ERROR, SE ESPERABAN: %i, caracteres, y se obtuvieron: %i\n", num1, num2);
	else
		printf("\nCORRECTO\n");
}

void testingChar()
{
	int num1, num2;

	printf("INICIO TESTERS DE %%c!!!\n\n");

	num1 = printf("hol%c", 'a');
	printf("\n");
	num2 = ft_printf("hol%c", 'a');
	compare(num1, num2);

	num1 = printf("%c%c%c%c", 'h', 'o', 'l', 'a');
	printf("\n");
	num2 = ft_printf("%c%c%c%c", 'h', 'o', 'l', 'a');
	compare(num1, num2);

	num1 = printf("%c\n%c\n%c", 42, 2, 70);
	printf("\n");
	num2 = ft_printf("%c\n%c\n%c", 42, 2, 70);
	compare(num1, num2);
	
	num1 = printf("%c\n%c\n%c\n%c", 48, 49, 50, 51);
	printf("\n");
	num2 = ft_printf("%c\n%c\n%c\n%c", 48, 49, 50, 51);
	compare(num1, num2);

	printf("\n\nFIN TESTERS DE %%c!!!\n\n");

}

void testingPlainText()
{
	int num1, num2;

	printf("INICIO TESTERS DE PLAIN TEXT!!!\n\n");


	num1 = printf("lorem ipsum");
	printf("\n");
	num2 = ft_printf("lorem ipsum");
	compare(num1, num2);

	num1 = printf("Propósito del lenguaje: Es importante definir claramente el propósito del lenguaje de programación que se está diseñando. ¿Está destinado a la programación web, la programación científica, la programación de sistemas, etc.?");
	printf("\n");
	num2 = ft_printf("Propósito del lenguaje: Es importante definir claramente el propósito del lenguaje de programación que se está diseñando. ¿Está destinado a la programación web, la programación científica, la programación de sistemas, etc.?");
	compare(num1, num2);

	num1 = printf("");
	printf("\n");
	num2 = ft_printf("");
	compare(num1, num2);
	
	num1 = printf("Never gonna give you up");
	printf("\n");
	num2 = ft_printf("Never gonna give you up");
	compare(num1, num2);

	printf("\nFIN TESTERS DE PLAIN TEXT!!!\n\n");
	
}

void testingString()
{
	printf("INICIO TESTERS DE %%s!!!\n\n");

	int num1, num2;

	num1 = printf("%s%s", "hola" , "que tal");
	printf("\n");
	num2 = ft_printf("%s%s", "hola", "que tal");
	compare(num1, num2);

	num1 = printf("%s%s", "" , (void *)0);
	printf("\n");
	num2 = ft_printf("%s%s", "", (void *)0);
	compare(num1, num2);

	printf("\n\nFIN TESTERS DE %%s!!!\n\n");	
}

void testingInt()
{
	printf("\n\nINICIO TESTERS DE %%i!!!\n\n");

	int num1, num2;

	num1 = printf("%i  %i", INT_MAX , INT_MIN);
	printf("\n");
	num2 = ft_printf("%i  %i", INT_MAX , INT_MIN);
	compare(num1, num2);

	num1 = printf("%i", (void *)0);
	printf("\n");
	num2 = ft_printf("%i", (void *)0);
	compare(num1, num2);

	num1 = printf("%i", 02323);
	printf("\n");
	num2 = ft_printf("%i", 02323);
	compare(num1, num2);

	printf("\n\nFIN TESTERS DE %%i!!!\n\n");

}

void testingUnsigned()
{
	printf("\n\nINICIO TESTERS DE %%u!!!\n\n");

	int num1, num2;

	num1 = printf("%u  %u", INT_MAX , INT_MIN);
	printf("\n");
	num2 = ft_printf("%u  %u", INT_MAX , INT_MIN);
	compare(num1, num2);

	num1 = printf("%u  %u", UINT_MAX , INT_MIN);
	printf("\n");
	num2 = ft_printf("%u  %u", UINT_MAX , INT_MIN);
	compare(num1, num2);

	num1 = printf("%u", (void *)0);
	printf("\n");
	num2 = ft_printf("%u", (void *)0);
	compare(num1, num2);

	num1 = printf("%u", 02323);
	printf("\n");
	num2 = ft_printf("%u", 02323);
	compare(num1, num2);

	printf("\n\nFIN TESTERS DE %%u!!!\n\n");

}

void testingPointer()
{
	printf("\n\nINICIO TESTERS DE %%p!!!\n\n");

	int num1, num2;

	int a = 2;

	int *p1 = &a;
	int *p2 = &a;

	num1 = printf("%p", p1);
	printf("\n");
	num2 = ft_printf("%p", p2);
	compare(num1, num2);

	num1 = printf("%p", (void *)0);
	printf("\n");
	num2 = ft_printf("%p", (void *)0);
	compare(num1, num2);

	printf("\n\nFIN TESTERS DE %%p!!!\n\n");

}


void testingHex()
{
	printf("\n\nINICIO TESTERS DE %%x!!!\n\n");

	int num1, num2;


	num1 = printf("%x  %X", INT_MAX , INT_MIN);
	printf("\n");
	num2 = ft_printf("%x  %X", INT_MAX , INT_MIN);
	compare(num1, num2);

	num1 = printf("%x  %X", UINT_MAX , INT_MIN);
	printf("\n");
	num2 = ft_printf("%x  %X", UINT_MAX , INT_MIN);
	compare(num1, num2);

	num1 = printf("%x", (void *)0);
	printf("\n");
	num2 = ft_printf("%x", (void *)0);
	compare(num1, num2);

	num1 = printf("%X", 02323);
	printf("\n");
	num2 = ft_printf("%X", 02323);
	compare(num1, num2);

	printf("\n\nFIN TESTERS DE %%x!!!\n\n");

}


int include(char *s1, char c)
{
	int i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("Por favor indica como argumentos los tests que quieres pasar\n ejemplo: \"ci\" pasará los tests para caracteres y enteros\n");
		return (-1);
	}
	if (include(argv[1], 'c'))
		testingChar();
	if (include(argv[1], 't'))
		testingPlainText();
	if (include(argv[1], 's'))
		testingString();
	if (include(argv[1], 'i'))
		testingInt();
	if (include(argv[1], 'u'))
		testingUnsigned();
	if (include(argv[1], 'x'))
		testingHex();
	if (include(argv[1], 'p'))
		testingPointer();
	return(0);
}
