//
// Created by Jamar Slave on 16/12/2019.
//

#include "inc/ft_printf.h"

int         main()
{
	int t;

	printf("mine:\n");
	t = ft_printf("%s", "");
	printf("<-\nreturned value : %i", t);
	printf("\norigin:\n");
	t = printf("%s", "");
	printf("<-\nreturned value : %i", t);
	printf("------------\n");
	return (0);
}

