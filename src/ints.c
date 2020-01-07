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
		num = (long int)va_arg(pf->ap, long int);
	pf->filling = ft_itoa(num);///itoa long long!
	print_int(pf);
}

void		handle_int_precision(t_pf *pf) {
	char *zero;
	int len;
	int num;

	num = ft_atoi(pf->filling);
	len = ft_strlen(pf->filling);
	if (pf->precision > len) {
		if (num < 0) {
			pf->filling = ft_itoa(num * -1);///FREEE
			len--;
		}
		if (num < 0 || (num > 0 && pf->need_sign == 1)) {
			zero = ft_memalloc(sizeof(char) * (pf->precision - len + 2));
			ft_memset(zero, '0', pf->precision - len + 1);
		} else {
			zero = ft_memalloc(sizeof(char) * (pf->precision - len + 1));
			ft_memset(zero, '0', pf->precision - len);
		}
		pf->filling = ft_strjoin(zero, pf->filling);////FREEEEEE
		if (num < 0)
			pf->filling[0] = '-';
		else if (num >= 0 && pf->need_sign == 1)
			pf->filling[0] = '+';
	} else if (pf->need_sign == 1 && num >= 0)
		pf->filling = ft_strjoin("+", pf->filling);///FREEEEE
}

void		handle_int_width(t_pf *pf)
{
	int len;
	int num;

	num = ft_atoi(pf->filling);
	len = ft_strlen(pf->filling);

	if (pf->need_sign == 1 && num >= 0 && pf->zero_filling == 0)
		pf->filling = ft_strjoin("+", pf->filling);//FREEEEE
	len = ft_strlen(pf->filling);
	if (pf->width > len)
	{
		if (num < 0)
		{
			pf->filling = ft_itoa(num*(-1));
			if (pf->align_left != 1)
			{
				ft_memcpy(&pf->str_empty[pf->width - len +1], pf->filling,ft_strlen(pf->filling));
				if (pf->zero_filling != 1)
					pf->str_empty[pf->width - len] = '-';
				else
					pf->str_empty[0] = '-';
			}
			else
			{
				ft_memcpy(&pf->str_empty[1], pf->filling, ft_strlen(pf->filling));
				//pf->str_empty = ft_strjoin("-", pf->str_empty);//FREEE
				pf->str_empty[0] = '-';
			}
		}
		else
		{
			if (pf->align_left != 1)
			{
				ft_memcpy(&pf->str_empty[pf->width - len], pf->filling, len);
				if (pf->need_sign == 1 && pf->zero_filling != 0)
					pf->str_empty[0] = '+';
			}
			else
			{
				if (num < 0)
					pf->filling = ft_itoa(num*(-1));
				ft_memcpy(pf->str_empty, pf->filling, len);
				//pf->str_empty = ft_strjoin("-", pf->str_empty);//FREEE
			}
		}
		free(pf->filling);
		pf->filling = pf->str_empty;


	}
}

void		print_int(t_pf *pf)
{
	if (pf->precision == -5 && pf->width == 0 && pf->align_left == 0)
	{
		if (pf->need_sign == 1 && ft_atoi(pf->filling) >= 0)
			pf->filling = ft_strjoin("+", pf->filling);////FREEEEE
	}
	if (pf->precision != -5)
		handle_int_precision(pf);
	if (pf->width != 0)
		handle_int_width(pf);
	ft_putstr(pf->filling);
	pf->printed+=ft_strlen(pf->filling);
}
