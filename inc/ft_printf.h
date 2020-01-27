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

#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <string.h>
#include "stdio.h"
#include <limits.h>
#include <float.h>

#define FLAGS " -+#0123456789"
#define TYPES "cspdiouxXf%"
#define INT_TYPES "diouxXf"
#define MAX_DBL "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000"
#define MAX_DBL_PREC "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368"

/////////////////////////////////////////////

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

////////////////////////////////////////////////

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
    char        *bits;
    char 		*filling;
    char 		*str_empty;
    long double num;
    int         flag;

}               t_pf;

/*
 * * ft_itoa_new
 */
char		                *ft_itoa_long_long(long long int n);
unsigned long long int				ft_atoi_long_long_uns(const char *str);
/*
 * * chars-int-percent.c
 */
int		handle_char(t_pf *pf);
int		handle_string(t_pf *pf);
int		handle_percent(t_pf *pf);
/*
 * * ft_printf.c
 */
int         ft_printf(const char *format, ...);
int 		read_args(t_pf *pf, const char *format);
int		print_all(t_pf *pf);
//size_t		find_len(long long int n);
/*
 * * ints.c
 */
int		handle_int(t_pf *pf);
int         handle_max_and_min_long_long(t_pf *pf);
void        ft_str_overlap_copy(char *str);
void        print_int_second_edition(t_pf *pf, long long int num);
void        turn_width_more_prec(t_pf *pf, long long int num, int len);
void        handle_int_precision_sec(t_pf *pf, long long int num);
void        handle_int_width_and_precision_sec(t_pf *pf, long long int num);
void        handle_int_width_sec(t_pf *pf, long long int num);
void        turn_width_more_prec_prec_more_num(t_pf *pf, int len , int i);
void        turn_width_more_prec_prec_less_num(t_pf *pf, int len, int i, int num);
void        handle_int_sign(t_pf *pf, long long int num);
void        handle_int_space_sec(t_pf *pf, long long int num);
void        print_int_second_edition(t_pf *pf, long long int num);
/*
 * * ints_utils
 */
char        *fill_zero_string(t_pf *pf, int len, long long int num);
void        put_sign(t_pf *pf, long long int num);
void        fill_empty_str_neg_num(t_pf *pf, int len, long long num);
void         fill_empty_str_pos_num(t_pf *pf, int len);
/*
 * * parsing.c
 */
int			check_flags(const char *curr, t_pf *pf);
int 		find_types(const char *str, char *parent);
int 		check_types(const char *curr, t_pf *pf);
int			zero_or_space_string(t_pf *pf);
int			check_size_flag(const char *curr, t_pf *pf);
/*
 * * print_oct_hex.c
 */
int		handle_pointer(t_pf *pf);
int		handle_hex(t_pf *pf);
int       handle_unsigned(t_pf *pf);
/*
 * precision.c
 */
//int			find_step(long long int num);
int			check_width(const char *curr, t_pf *pf);
int 		check_precision(const char *curr, t_pf *pf);
int			check_all_precisions(const char *curr, t_pf *pf);
/*
 * * print_str_char.c
 */
void		fill_and_print_string(t_pf *pf);
void 		print_char(t_pf *pf);
void		transform_str_precision(t_pf *pf);
char 		*cut_string(char *str, int q);
/*
 * * utils.c
 */
t_pf 		*init_pf();
void		upper_symb(char *str);
void		zero_pf(t_pf *pf);

/*
 * floats
 * */
int		handle_float(t_pf *pf);
int		ft_length(long double num, int prec);
char	*ft_ftos_sec(long double num, int prec);
long double	ft_round(long double x, long double acc);
char	*spaces(char c, int n);
double	ft_power(double nb, double power);
int		ft_if_in_str(char *s1, char s2);
void	printf_fill(t_pf *pf, long double tmp, int len);
void	printf_float_2(long double tmp, int len, t_pf *pf);
void	sign_2(t_pf *pf);
void	printf_fill_4(t_pf *pf);
void	printf_fill_3(t_pf *pf);
void	printf_fill_2(t_pf *pf);
void	printf_float_3(long double tmp, t_pf *pf);
void	print_float(t_pf *pf, long double num);
int		dbl_2(t_pf *pf);
int		dbl(t_pf *pf);
int		sign(t_pf *pf, long double tmp, int len);
/*
 * oct_test.c
 */
int		handle_oct(t_pf *pf);
void		print_int_oct(t_pf *pf);
char		*ft_itoa_long_long_uns(unsigned long long int n);

void        print_int_hex(t_pf *pf);
#endif
