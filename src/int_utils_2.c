/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:48:20 by jslave            #+#    #+#             */
/*   Updated: 2020/01/27 18:48:24 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        handle_int_width_and_precision(t_pf *pf, long long int num)
{
	int len;

	handle_int_precision(pf, num);
	len = ft_strlen(pf->filling);
	if (pf->width > pf->precision)
	{
		if (pf->precision != 0 && pf->precision != -1)
			turn_width_more_prec(pf, num, len);
		else if (pf->precision <= 0 && num == 0)
		{
			ft_memdel((void **)&pf->filling);
			pf->filling = ft_strdup(pf->str_empty);
			if (pf->need_sign == 1 && pf->align_left != 1)
				pf->filling[ft_strlen(pf->filling) - 1] = '+';
			else if (pf->need_sign == 1 && pf->align_left == 1)
				pf->filling[0] = '+';
		}
	}
	else
		handle_int_precision(pf, num);
}

void        handle_int_width(t_pf *pf, long long int num)
{
	int len;

	len = ft_strlen(pf->filling);
	if (pf->width > len)
	{
		if (num < 0)
			fill_empty_str_neg_num(pf, len, num);
		else
			fill_empty_str_pos_num(pf, len);
		ft_memdel((void **)&pf->filling);
		pf->filling = ft_strdup(pf->str_empty);
	}
}

void		width_more_prec_plus(t_pf *pf)
{
	int i;

	i = pf->width -1;
	while (pf->filling[i] == ' ')
		i--;
	while (i >= 0)
	{
		pf->filling[i + 1] = pf->filling[i];
		i--;
	}
	pf->filling[0] = '+';
}

void        turn_width_more_prec_more_num(t_pf *pf, int len , int i)
{
	if ((i == len || i == 0) && pf->filling[pf->width -1] != ' ')
		pf->filling = ft_strjoinfree_both(ft_strdup("+"), pf->filling);
	else if ((i == len || i == 0) && pf->filling[pf->width -1] == ' ')
		width_more_prec_plus(pf);
	else if (i < len && i)
	{
		if (pf->filling[0] == '0')
			pf->filling[0] = '+';
		else if (pf->filling[i - 1])
			pf->filling[i - 1] = '+';
	}
}

void        ft_str_overlap_copy(char *str)
{
	char *tmp;
	size_t len;
	int i;
	int j;

	i = 1;
	j = 0;
	len = ft_strlen(str);

	tmp = ft_strnew(len);
	ft_memcpy(tmp, str, len);
	while (len-1)
	{
		str[i] = tmp[j];
		i++;
		j++;
		len--;
	}
	free(tmp);
}



