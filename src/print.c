/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 15:19:28 by jslave            #+#    #+#             */
/*   Updated: 2019/12/21 15:19:30 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_char(t_pf *pf)
{
	char alpha;

	alpha = va_arg(pf->ap, int);
	pf->filling = ft_memalloc(sizeof(char) * 2);
	pf->filling[0] = alpha;
};

void		handle_string(t_pf *pf)
{

	pf->filling = (char *)va_arg(pf->ap, char *);///prec!!!!
};

void		handle_pointer(t_pf *pf)
{
	unsigned long long int pnt;

	pnt = (unsigned long long int)va_arg(pf->ap, int);//ширина и точность!!!!
	pf->filling = ft_itoa_base(pnt, 16);
	pf->filling = ft_strjoin("0x", pf->filling);//LEAK
};

void		handle_int(t_pf *pf)
{
	int num;

	num = va_arg(pf->ap, int);
	pf->filling = ft_itoa(num);
};

void		handle_oct_and_unsigned(t_pf *pf)
{
	unsigned int num;
	char *str;

	num = (unsigned int)va_arg(pf->ap, unsigned int);
	if (pf->type == 'o')
	{
		pf->filling = ft_itoa_base(num, 8);
		if (pf->need_format == 1)
			str = ft_strjoin("0", pf->filling);//LEAK
	}
	else if (pf->type == 'u')
		pf->filling = ft_itoa(num);
};

void		handle_hex(t_pf *pf)
{
	unsigned int num;

	num = (unsigned int)va_arg(pf->ap, unsigned int);
	pf->filling = ft_itoa_base(num, 16);
	if (pf->type == 'X')
		upper_symb(pf->filling);
};
void		handle_float(t_pf *pf)
{
	(void)pf;
};

void		handle_percent(t_pf *pf)
{
	pf->filling = ft_memalloc(sizeof(char) *2);
	pf->filling[0] = '%';
};

char 		*cut_string(char *str, int q)
{
	char *res;

	res = ft_memalloc(sizeof(char) * q + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, str, q);
	return (res);
}

void		transform_precision(t_pf *pf)
{
	int len;
	char *zero;
	char *test;

	len = ft_strlen(pf->filling);
	if (pf->precision > len && (pf->type == 'i' || pf->type == 'd' || pf->type == 'o' || pf->type == 'x' || pf->type == 'X' || pf->type == 'u' || pf->type == 'f'))///ADD TYPES INT
	{
		zero = ft_memalloc(pf->precision - len + 1);
		ft_memset(zero, '0', pf->precision - len);
		test = ft_strjoinfree(zero, pf->filling);
		pf->filling = test;//LEAK
	}
	else if (pf->precision < len && pf->type == 's')
	{
		char *test;
		test = cut_string(pf->filling, (pf->precision));
		if (*test)
			pf->filling = test;//LEAK
	}
}

void		fill_and_print_string(t_pf *pf)
{
	int len;

	transform_precision(pf);
	len = ft_strlen(pf->filling);
	if (pf->width == 0 || pf->width < len)
	{
		ft_putstr(pf->filling);
		pf->printed+=len;
	}
	else if (pf->width >= len)
	{
		if (pf->align_left == 1)
			ft_memcpy(pf->str_empty, pf->filling, len);
		else
			ft_memcpy((pf->str_empty + ft_strlen(pf->str_empty)) - len, pf->filling, len);
		ft_putstr(pf->str_empty);
		pf->printed+=ft_strlen(pf->str_empty);
	}
}