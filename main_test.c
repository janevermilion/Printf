//
// Created by Jamar Slave on 16/12/2019.
//

#include "inc/ft_printf.h"
//c s p d i o u x X hh, h, l and ll %% #0-+
int         main()
{
	int *pnt;
	char *ch;

printf("mine:\n");


int t = ft_printf("%+.7i", 234);
printf("\nreturned value : %i", t);
printf("\norigin:\n");


 t = printf("%+.7i", 234);
printf("\nreturned value : %i", t);

  return (0);
}
