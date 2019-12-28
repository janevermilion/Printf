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
	if (pf->precision > len && (pf->type == 'i' || pf->type == 'd' || pf->type == 'o'
	|| pf->type == 'x' || pf->type == 'X' || pf->type == 'u' || pf->type == 'f'))///ADD TYPES INT
	{
		zero = ft_memalloc(pf->precision - len + 1);
		ft_memset(zero, '0', pf->precision - len);
		test = ft_strjoinfree(zero, pf->filling);
		pf->filling = test;//LEAK
	}
	else if (pf->precision > 0 && pf->precision < len && pf->type == 's')
	{
		test = cut_string(pf->filling, (pf->precision));
		if (*test)
			pf->filling = test;//LEAK
	}
	else if (pf->precision == 0)
		pf->filling = "";
}

void		fill_and_print_string(t_pf *pf)
{
	int len;

		transform_precision(pf);
		len = ft_strlen(pf->filling);
		if (pf->precision != -1 && (pf->width == 0 || pf->width < len))
		{
			ft_putstr(pf->filling);
			pf->printed+=len;
		}
		else if (pf->width >= len && pf->precision != -1)
		{
			if (pf->align_left == 1)
				ft_memcpy(pf->str_empty, pf->filling, len);
			else
				ft_memcpy((pf->str_empty + ft_strlen(pf->str_empty)) - len, pf->filling, len);
			ft_putstr(pf->str_empty);
			pf->printed+=ft_strlen(pf->str_empty);
		}
		else if ((pf->width >= len && pf->precision == -1))
		{
			ft_putstr(pf->str_empty);
			pf->printed+=ft_strlen(pf->str_empty);
		}
}

void		print_all(t_pf *pf)
{
	if (pf->width != 0)
		zero_or_space_string(pf);
	if (pf->type == 'c')
		handle_char(pf);
	else if (pf->type == 's')
		handle_string(pf);
	else if (pf->type == 'p')
		handle_pointer(pf);
	else if (pf->type == 'd' || pf->type == 'i')
		handle_int(pf);
	else if (pf->type == 'o' || pf->type == 'u')
		handle_oct_and_unsigned(pf);
	else if (pf->type == 'x' || pf->type == 'X')
		handle_hex(pf);
	else if (pf->type == 'f')
		handle_float(pf);
	else if (pf->type == '%')
		handle_percent(pf);
	fill_and_print_string(pf);
}