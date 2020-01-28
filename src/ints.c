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

void		turn_width_more_prec_less_num(t_pf *pf, int len, int i, int num)
{
	if (i == 0 && pf->zero_filling == 1 && pf->width >
(int)find_len_of_num(num) && pf->align_left != 1)
		pf->filling[0] = '+';
	else if ((i == len || i == 0) && pf->filling[pf->width - 1] != ' ')
		pf->filling = ft_strlen(pf->filling) ? ft_strjoinfree_both
(ft_strdup("+"), pf->filling) : ft_strjoinfree_s1
(ft_strdup("+"), pf->filling);
	else if ((i == len || i == 0) && pf->filling[pf->width - 1] == ' ' && num)
		width_more_prec_plus(pf);
	else if (i < len || (num == 0 && i == len))
	{
		if (pf->filling[0] == '0' || (pf->filling[i - 1] &&
pf->align_left == 1))
			pf->filling[0] = '+';
		else if (pf->filling[i - 1] && pf->align_left != 1)
			pf->filling[i - 1] = '+';
	}
}

void		handle_int_sign(t_pf *pf, long long int num)
{
	int		i;
	char	stop;
	int		len;

	len = (int)ft_strlen(pf->filling);
	i = 0;
	stop = ' ';
	while (pf->filling[i] == stop && pf->filling[i] != '\0')
		i++;
	if (pf->precision > (int)find_len_of_num(num) && pf->width > pf->precision)
		turn_width_more_prec_more_num(pf, len, i);
	else if (pf->precision < (int)find_len_of_num(num) && pf->width >
pf->precision)
		turn_width_more_prec_less_num(pf, len, i, num);
	else if ((pf->width == 0 && pf->precision < 0) || pf->width <=
pf->precision)
		pf->filling = ft_strlen(pf->filling) ?
ft_strjoinfree_both(ft_strdup("+"), pf->filling) :
ft_strjoinfree_s1(ft_strdup("+"), pf->filling);
}

void		handle_int_space(t_pf *pf, long long int num)
{
	int len;

	if (handle_max_and_min_long_long(pf) == 1)
		return ;
	len = find_len_of_num((int)num);
	if (num >= 0 && pf->need_sign != 1)
	{
		if (pf->width <= len)
			pf->filling = ft_strjoinfree_both(ft_strdup(" "),
pf->filling);
		if (pf->width > len + 1 && pf->align_left == 1)
			ft_str_overlap_copy(pf->filling);
		pf->filling[0] = ' ';
	}
}

void		print_int(t_pf *pf, long long int num)
{
	if (pf->precision >= 0 && pf->width > 0)
		handle_int_width_and_precision(pf, num);
	else if (pf->precision < 0)
	{
		if (pf->width != 0)
			handle_int_width(pf, num);
		else
			handle_int_precision(pf, num);
	}
	else if (pf->precision > 0 && pf->precision > (int)find_len_of_num(num))
		handle_int_precision(pf, num);
	if (pf->need_sign == 1 && num >= 0)
		handle_int_sign(pf, num);
	if (pf->need_spase == 1 && pf->need_sign != 1)
		handle_int_space(pf, num);
	ft_putstr(pf->filling);
	pf->printed += ft_strlen(pf->filling);
}

int			handle_int(t_pf *pf)
{
	long long int num;

	num = 0;
	if (ft_strequ(pf->size_flag, "\0") == 1 || (pf->printed > 0
	&& pf->size_flag == NULL))
		num = va_arg(pf->ap, int);
	else if (ft_strequ(pf->size_flag, "hh") == 1)
		num = (signed char)va_arg(pf->ap, int);
	else if (ft_strequ(pf->size_flag, "h") == 1)
		num = (short)va_arg(pf->ap, int);
	else if (ft_strequ(pf->size_flag, "ll") == 1)
		num = (long long int)va_arg(pf->ap, long long int);
	else if (ft_strequ(pf->size_flag, "l") == 1)
		num = (long int)va_arg(pf->ap, long int);
	if (num == 0 && (pf->precision == -1 || pf->precision == 0))
		pf->filling = ft_strdup("");
	else
		pf->filling = ft_itoa_long_long(num);
	print_int(pf, num);
	return (pf->printed);
}
