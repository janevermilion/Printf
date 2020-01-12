//
// Created by Jamar Slave on 16/12/2019.
//

#include "inc/ft_printf.h"
//c s p d i o u x X hh, h, l and ll %% #0-+
int         main()
{
printf("mine:\n");
int t = ft_printf("%#05X", 43);
printf("<-\nreturned value : %i", t);
printf("\norigin:\n");
 t = printf("%#05x", 43);
printf("<-\nreturned value : %i", t);
printf("\n------------\n");
  return (0);
}
