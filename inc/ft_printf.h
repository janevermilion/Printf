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

#define FLAGS "cspdiouxXfyb% 0123456789"

typedef struct  s_pf
{
    va_list 	ap;
    int 		width;
    int 		printed;
}               t_pf;

int         ft_printf(const char *format, ...);
t_pf 		*init_pf();
int			check_sp(const char *curr, t_pf *pf);
int			check_ints(const char *curr, t_pf *pf);
int			check_width(const char *curr, t_pf *pf);
int			check_percent(const char *curr, t_pf *pf);
int			check_chars(const char *curr, t_pf *pf);
int 		check_pointer(const char *curr, t_pf *pf);

char		*ft_itoa_long_long(long long int n);





#endif
