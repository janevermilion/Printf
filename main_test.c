//
// Created by Jamar Slave on 16/12/2019.
//

#include "inc/ft_printf.h"
//c s p d i o u x X hh, h, l and ll %% #0-+
int         main()
{
    static unsigned char 		uch_pos_1 = 100;
    static unsigned short		ush_pos_1 = 3047;
    static unsigned int		ui_pos_1 = 878023;
    static unsigned long		ul_pos_1 = 22337203685477;
    static unsigned long long	ull_pos_1 = 22337203685477;
    static unsigned long long  ullmax = 9223372036854775807;
    static unsigned long  		ulmax = 9223372036854775807;

printf("mine:\n");
int t = ft_printf("%.0i", 0);
printf("<-\nreturned value : %i", t);
printf("\norigin:\n");
 t = printf("%.0i", 0);
printf("<-\nreturned value : %i", t);
printf("\n------------\n");
  return (0);
}
