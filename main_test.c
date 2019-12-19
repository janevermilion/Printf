//
// Created by Jamar Slave on 16/12/2019.
//

#include "inc/ft_printf.h"
//c s p d i o u x X hh, h, l and ll %% #0-+
int         main()
{
	int *pnt;
   // int cat = -10;
int dog = 123;
  /*int res;
  res = printf("%5%");
  printf("\norigin returned: %i\n", res);
  printf("......\n");
  res = ft_printf("%5%");
  printf("\nMine returned: %i\n", res);

  char cat[7] = "catcat";//pq
  ft_printf("string: %s", cat);
	*/
  char *test;
  //ft_printf("%p", test);
  int res = ft_printf("%i5554", dog);
	printf("\nres: %i", res);

  return (0);
}
