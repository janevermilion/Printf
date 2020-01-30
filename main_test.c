//
// Created by Jamar Slave on 16/12/2019.
//

#include "inc/ft_printf.h"

int         main()
{
/*
	ft_printf("%+d", 42);printf("\n");
	ft_printf("%+d", 0);printf("\n");
	ft_printf("% +d", 42);printf("\n");
	ft_printf("%+ d", 42);printf("\n");
	ft_printf("%  +d", 42);printf("\n");
	ft_printf("%+  d", 42);printf("\n");
	ft_printf("% ++d", 42);printf("\n");
	ft_printf("%++ d", 42);printf("\n");

	/*
	ft_printf("%++ d", 42);
	ft_printf("%+d", 0);
	ft_printf("\n");
    ft_printf("%%\n");
    ft_printf("%d\n", 42);
    ft_printf("%d%d\n", 42, 41);
    ft_printf("%d%d%d\n", 42, 43, 44);
    ft_printf("%ld\n", 2147483647);
    ft_printf("%lld\n", 9223372036854775807);
    ft_printf("%x\n", 505);
    ft_printf("%X\n", 505);
    ft_printf("%p\n", &ft_printf);
    ft_printf("%20.15d\n", 54321);
    ft_printf("%-10d\n", 3);
    ft_printf("% d\n", 3);
    ft_printf("%+d\n", 3);
    ft_printf("%010d\n", 1);
    ft_printf("%hhd\n", 0);
    ft_printf("%jd\n", 9223372036854775807);
    ft_printf("%zd\n", 4294967295);
    ft_printf("%\n");
    ft_printf("%U\n", 4294967295);
    ft_printf("%u\n", 4294967295);
    ft_printf("%o\n", 40);
    ft_printf("%%#08x\n", 42);
    ft_printf("%x\n", 1000);
    ft_printf("%#X\n", 1000);
    ft_printf("%s\n", NULL);
    ft_printf("%s%s\n", "test", "test");
    ft_printf("%s%s%s\n", "test", "test", "test");
    ft_printf("%C\n", 15000);

/*
int i = 0;
while (i++ < 10000)
{
	ft_printf("%++ d", 42);
	printf(" ");
	if (i % 100 == 0)
		printf("\n");
}
*/
	printf("mine:\n");
	int t = ft_printf("%+-5.i", 0);
	printf("<-\nreturned value : %i", t);
	printf("\norigin:\n");
	t = printf("%+-5.i", 0);
	printf("<-\nreturned value : %i", t);
	printf("\n------------\n");


	return (0);
}

