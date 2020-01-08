//
// Created by Jamar Slave on 16/12/2019.
//

#include "inc/ft_printf.h"
//c s p d i o u x X hh, h, l and ll %% #0-+
int         main()
{
	int *pnt;
	char *ch;
	static char 		ch_pos_1 = 100, ch_neg_1 = -87;
	static short		sh_pos_1 = 3047, sh_neg_1 = -8875;
	static int			i_pos_1 = 878023;
	static long		l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
	static long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
	static long		lmax	= 9223372036854775807;
	static long		lmin	= -9223372036854775807;
	static long long llmax = 9223372036854775807;
	static long long	llmin = -9223372036854775807ll;
printf("mine:\n");
int t = ft_printf("this % i number", 17);
printf("\nreturned value : %i", t);
printf("\norigin:\n");
 t = printf("this % i number", 17);
printf("\nreturned value : %i", t);
printf("\n------------\n");
  return (0);
}
