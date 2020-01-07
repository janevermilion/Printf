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
    char 		*filling;
    char 		*str_empty;

}               t_pf;

int         ft_printf(const char *format, ...);
t_pf 		*init_pf();
int			check_width(const char *curr, t_pf *pf);
int 		check_precision(const char *curr, t_pf *pf);
int			check_size_flag(const char *curr, t_pf *pf);
int			check_flags(const char *curr, t_pf *pf);
void		upper_symb(char *str);
void		handle_char(t_pf *pf);
void		handle_string(t_pf *pf);
void		handle_pointer(t_pf *pf);
void		handle_int(t_pf *pf);
void		handle_oct_and_unsigned(t_pf *pf);
void		handle_hex(t_pf *pf);
void		handle_float(t_pf *pf);
void		handle_percent(t_pf *pf);
void		fill_and_print_string(t_pf *pf);
void		transform_str_precision(t_pf *pf);
void		print_all(t_pf *pf);
int 		check_types(const char *curr, t_pf *pf);
int			zero_or_space_string(t_pf *pf);
int 		find_types(const char *str);
void		print_int(t_pf *pf);


void		zero_pf(t_pf *pf);




#endif
