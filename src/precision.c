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
	if (num < 0)
		return (0);
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

int 	check_precision(const char *curr, t_pf *pf)
{

	int i;
	int precision;
	int width;

	i = 0;

	while (curr[i] && find_types(&(curr[i])) != 1)
	{
		if (curr[i] == '.')
		{
			if (ft_isdigit(curr[++i]) == 1 && curr[i] != '0' && find_types(&(curr[i])) != 1)
			{
				precision = ft_atoi(&curr[i]);
				if (precision > 0)
					pf->precision = precision;
			}
			else if (curr[i] == '*')
			{
				precision= (int)va_arg(pf->ap, int);
				pf->precision = precision;
			}
			else if (curr[i] == '0')
			{
				precision = ft_atoi(&curr[i]);
				pf->precision = precision;
			}
			else if (find_types(&(curr[i])) == 1)
			{
				pf->precision = -1;
				i+=1;
				break;
			}
			else
				pf->precision = -1;
		}
		i++;
	}
	if (pf->precision == -1)
		return (i - 1);
	if (pf->precision == 0)
		return (i);
	if (pf->precision > 0)
	{
		width = find_step(pf->precision);
		return ((int)(&curr[i - 1] - curr) + width);
	}

	return (0);
}