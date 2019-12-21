/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:01:00 by jslave            #+#    #+#             */
/*   Updated: 2019/12/14 17:01:08 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

//#-+.*0123456789hLljz
//#include "libft.h"
#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <string.h>
#include "stdio.h"
#include <limits.h>

#define FLAGS " -+#0123456789"
#define TYPES "cspdiouxXf%"
typedef struct  s_pf
{
    va_list 	ap;
    int 		width;
    int 		printed;
    int			align_left;
    int			need_sign;
    int 		need_spase;
    int			need_format;
    int 		zero_filling;
    int 		precision;
    char 		type;
    char 		*size_flag;
    int 		length; //LL HH H L
    char 		*str;

}               t_pf;

int         ft_printf(const char *format, ...);
t_pf 		*init_pf();
//int			check_sp(const char *curr, t_pf *pf);
//int			check_ints(const char *curr, t_pf *pf);
int			check_width(const char *curr, t_pf *pf);
//int			check_percent(const char *curr, t_pf *pf);
//int			check_chars(const char *curr, t_pf *pf);
//int 		check_pointer(const char *curr, t_pf *pf);
int 		check_precision(const char *curr, t_pf *pf);
//char		*ft_itoa_long_long(long long int n);
void		lower_symb(char *str);
void		print_char(t_pf *pf);
void		print_string(t_pf *pf);
void		print_pointer(t_pf *pf);
void		print_int(t_pf *pf);
void		print_oct_and_unsigned(t_pf *pf);
void		print_hex(t_pf *pf);
void		print_float(t_pf *pf);
void		print_percent(t_pf *pf);

void		zero_pf(t_pf *pf);




#endif
