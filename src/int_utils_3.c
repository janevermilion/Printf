/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:51:17 by jslave            #+#    #+#             */
/*   Updated: 2020/01/27 18:51:19 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prec_less_width(t_pf *pf, long long int num, int len)
{
	char *zero;

	if (pf->align_left == 1)
		ft_memcpy(pf->str_empty, pf->filling, ft_strlen(pf->filling));
	else
	{
		int test = find_len_of_num(num);
		if (pf->precision >= test)
		{
			pf->filling = ft_itoa_long_long(num * -1);
			int test2 = pf->precision - ft_strlen(pf->filling);
			zero = ft_strnew(test2);
			ft_memset(zero, '0', test2);
			pf->filling = ft_strjoinfree_both(zero, pf->filling);
			pf->filling = ft_strjoinfree_both(ft_strdup("-"),
											  pf->filling);
			ft_memcpy(&pf->str_empty[pf->width - ft_strlen(pf->filling)],
					  pf->filling, ft_strlen(pf->filling));
		}
		else
			ft_memcpy(&pf->str_empty[pf->width - len], pf->filling,
					  ft_strlen(pf->filling));
	}
}

void        turn_width_more_prec(t_pf *pf, long long int num, int len)
{
	if (num < 0 && ft_strlen(pf->str_empty) > (size_t)find_len_of_num(num))
	{
		if (pf->precision < pf->width)
		{
			prec_less_width(pf, num, len);
			ft_memdel((void **)&pf->filling);
			pf->filling = ft_strdup(pf->str_empty);
		}
	}
	else if (ft_strlen(pf->str_empty) > (size_t)len)
	{
		if (pf->align_left != 1)
			ft_memcpy(&pf->str_empty[pf->width - len], pf->filling, len);
		else
			ft_memcpy(pf->str_empty, pf->filling, len);
		ft_memdel((void **)&pf->filling);
		pf->filling = ft_strdup(pf->str_empty);
	}
}

void        handle_int_precision(t_pf *pf, long long int num)
{
	char *zero;
	int len;

	len = ft_strlen(pf->filling);
	if (pf->precision > len)
	{
		if (num < 0)
		{
			pf->filling = ft_itoa_long_long(num * -1);
			len--;
		}
		zero = fill_zero_string(pf, len, num);
		pf->filling = ft_strjoinfree_both(zero, pf->filling);
		if (num < 0)
			put_sign(pf, num);
	}
}
