/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:51:31 by jslave            #+#    #+#             */
/*   Updated: 2019/12/17 16:51:33 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			find_step(int num)
{
	int res;

	res = 0;

	while (num)
	{
		res++;
		num = num / 10;
	}
	return (res);
}

int			check_width(const char *curr, t_pf *pf)
{
	int qual;
	int width_of_num;

	if (ft_isdigit(*curr) == 1)
	{
		qual = ft_atoi(curr);
		if (qual >= 0)
		{
			pf->width = qual;
			width_of_num = find_step(qual);
			return (width_of_num);
		}
	}
	if (*curr == '*')
	{
		qual = (int)va_arg(pf->ap, int);
		pf->width = qual;
		return (1);
	}
	return (0);
}

int 		check_precision(const char *curr, t_pf *pf)
{
	int precision;
	int width;

	if (*curr == '.')
	{
		precision = ft_atoi(++curr);
		if (precision > 0)
		{
			pf->precision = precision;
			width = find_step(precision);
			return (width + 1);
		}
	}
	if (*(curr + 1) == '*')
	{
		precision= (int)va_arg(pf->ap, int);
		pf->precision = precision;
		return (1);
	}
	return (0);
}