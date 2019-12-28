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
/*
 * Для целочисленных спецификаторов (d, i, o, u, x, X) - точность указывает минимальное количество записываемых цифр.
 * Если записываемое значение короче этого числа, результат дополняется начальными нулями.
 * Значение не усекается, даже если результат длиннее. Точность 0 означает, что ни один символ не записывается
 * для значения 0. Для спецификаторов e, E и f - это количество цифр, которые будут напечатаны после десятичной точки.
 * Для спецификаторов g и G - это максимальное количество значащих цифр для печати. Для s - это максимальное
 * количество символов для печати. По умолчанию все символы печатаются до тех пор, пока не встретится конечный
 * нулевой символ. Для типа c - это не имеет никакого эффекта. Если точность не указана, по умолчанию используется
 * значение 1. Если период указан без явного значения точности, предполагается 0.
 */
/*
int 		check_precision(const char *curr, t_pf *pf)
{
	int precision;
	int width;
	int i;

	width = 0;
	i = 0;
	while (strchr(curr, '.'))
	{
		pf->precision = 0;
		precision = 0;
		curr++;
		if (ft_isdigit(*curr) == 1)
		{
			precision = ft_atoi(curr);
			if (precision > 0)
				pf->precision = precision;
		}
		else if (*curr == '*')
		{
			precision= (int)va_arg(pf->ap, int);
			pf->precision = precision;
		}
		else //if (find_types(curr) == 0)
			pf->precision = -1;
		i++;
		width += find_step(pf->precision);
	}
	if (i > 1)
		width+=(i - 1);
	else
		width+=i;//TERN

	return (width);
}

int 		check_precision(const char *curr, t_pf *pf)
{
	int precision;
	int width;
	char *dot;

	precision = 0;
	width = 0;
	dot = ft_strchr(curr, '.');

	if (dot < curr)
	{
		if (ft_isdigit(*(++dot)) == 1)
		{
			precision = ft_atoi(dot);
			if (precision > 0)
				pf->precision = precision;
			else if (*dot == '*')
			{
				precision= (int)va_arg(pf->ap, int);
				pf->precision = precision;
			}
			width += find_step(pf->precision);
		}
	}
	return (width);
}
*/
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