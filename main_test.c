//
// Created by Jamar Slave on 16/12/2019.
//

#include "inc/ft_printf.h"

int         main()///2468
{
	int t;

	printf("mine:\n");
	t = ft_printf("%23.5lu", ULLONG_MAX);
	printf("<-\nreturned value : %i", t);
	printf("\norigin:\n");
	t = printf("%23.5lu", ULLONG_MAX);
	printf("<-\nreturned value : %i", t);
	printf("\n------------\n");

	return (0);
}

