/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:17:57 by jslave            #+#    #+#             */
/*   Updated: 2019/12/26 16:17:58 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_int(t_pf *pf)
{
	long long int num;

	num = 0;
	if (pf->size_flag == NULL)
		num = va_arg(pf->ap, int);
	else if (ft_strequ(pf->size_flag, "hh") == 1)
		num = (signed char)va_arg(pf->ap, int);
	else if (ft_strequ(pf->size_flag, "h") == 1)
		num = (short)va_arg(pf->ap, int);
	else if (ft_strequ(pf->size_flag, "ll") == 1)
		num = (long long int)va_arg(pf->ap, long long int);
	else if (ft_strequ(pf->size_flag, "l") == 1)
		num = (long int)va_arg(pf->ap,  long int);
	pf->filling = ft_itoa_long_long(num);///itoa long long!
	print_int(pf);
}



void		handle_int_precision(t_pf *pf)
{
	char *zero;
	int len;
	long long int num = ft_atoi_long_long(pf->filling);

	len = ft_strlen(pf->filling);
	if (pf->precision > len)
	{
		if (num < 0)
		{
			pf->filling = ft_itoa_long_long(num * -1);///FREEE
			len--;
		}
		zero = fill_zero_string(pf, len, num);
		pf->filling = ft_strjoin(zero, pf->filling);////FREEEEEE
		put_sign(pf, num);
	}
	else if (pf->need_sign == 1 && num >= 0)
		pf->filling = ft_strjoin("+", pf->filling);///FREEEEE
}

void		handle_int_width(t_pf *pf)
{
	int len;
	long long int num;

    num = ft_atoi_long_long(pf->filling);
	if (pf->need_sign == 1 && num >= 0 && pf->zero_filling == 0)
		pf->filling = ft_strjoin("+", pf->filling);//FREEEEE
	len = ft_strlen(pf->filling);
	if (pf->width > len)
	{
		if (num < 0)
            fill_empty_str_neg_num(pf, len, num);
		else
		    fill_empty_str_pos_num(pf, len);
		free(pf->filling);
		pf->filling = pf->str_empty;
	}
}

void		handle_int_width_and_precision(t_pf *pf)
{
	int len;

	len = ft_strlen(pf->filling);
	if (pf->zero_filling == 1)
		ft_memset(pf->str_empty, ' ', pf->width);
	if (pf->width > pf->precision)
	{
		if (pf->align_left != 1)
			ft_memcpy(&pf->str_empty[pf->width - len], pf->filling, len);
		else
			ft_memcpy(pf->str_empty, pf->filling, len);
		free(pf->filling);
		pf->filling = pf->str_empty;
	}
}

void		print_int(t_pf *pf)
{
	if (pf->precision == -5 && pf->width == 0 && pf->align_left == 0)
	{
		if (pf->need_sign == 1 && ft_atoi_long_long(pf->filling) >= 0)
			pf->filling = ft_strjoin("+", pf->filling);////FREEEEE
	}
	if (pf->precision != -5)
		handle_int_precision(pf);
	if (pf->width != 0 && pf->precision == -5)
		handle_int_width(pf);
	else if (pf->width != 0 && pf->precision != -5)
		handle_int_width_and_precision(pf);
	ft_putstr(pf->filling);
	pf->printed+=ft_strlen(pf->filling);
}
