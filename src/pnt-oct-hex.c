/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:28:01 by jslave            #+#    #+#             */
/*   Updated: 2019/12/17 16:28:03 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_pointer(t_pf *pf)
{
	unsigned long long int pnt;

	pnt = (unsigned long long int)va_arg(pf->ap, void *);//ширина и точность!!!!
	pf->filling = ft_itoa_base_unsigned(pnt, 16);
	pf->filling = ft_strjoin("0x", pf->filling);//LEAK
	fill_and_print_string(pf);
}

void        handle_unsigned(t_pf *pf)
{
    unsigned int num;

    num = (unsigned int)va_arg(pf->ap, unsigned int);
    if (pf->type == 'u')
        pf->filling = ft_itoa(num);
    print_int(pf);
}

void		handle_hex(t_pf *pf)
{
	unsigned int num;

	num = (unsigned int)va_arg(pf->ap, unsigned int);
	pf->filling = ft_itoa_base(num, 16);
	if (pf->type == 'X')
		upper_symb(pf->filling);
};