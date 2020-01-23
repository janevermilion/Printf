//
// Created by Jamar Slave on 16/12/2019.
//

#include "inc/ft_printf.h"
//c s p d i o u x X hh, h, l and ll %% #0-+
int         main()
{
printf("mine:\n");
int t = ft_printf("%.2s is a string %d", "this");
//int t = ft_printf("text: %#.o %#.0o", 0, 0);

printf("<-\nreturned value : %i", t);

printf("\norigin:\n");
    t = printf("%.2s is a string %d", "this", 7);
printf("<-\nreturned value : %i", t);
printf("\n------------\n");
  return (0);
}
/*
 *  перекопать все на предсет маллока и фри со строками
 */

//transform he
//x format in hex.c refactor

//разобрать с затиранием строк а то течет каждый раз чистить филлин и эпти поменяно в стр и инт