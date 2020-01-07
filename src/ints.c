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
};


void 		transform_int_precision(t_pf *pf)
{
	char *zero;
	int len;
	int num;

	len = ft_strlen(pf->filling);
	if (pf->precision > len)
	{
		num = ft_atoi(pf->filling);
		if (num < 0)
		{
			zero = ft_memalloc(sizeof(char) * (pf->precision - len + 2));
			ft_memset(zero,'0', pf->precision - len +1);
			zero = ft_strjoin("-", zero);///FREEEE
			pf->filling = ft_itoa(num * (-1));
		}
		else
		{
			if (pf->need_sign == 1)
			{
				zero = ft_memalloc(sizeof(char) * (pf->precision - len + 1));
				ft_memset(zero,'0', pf->precision - len);
				zero = ft_strjoin("+", zero);///FREEEE
			}
			else
			{
				zero = ft_memalloc(sizeof(char) * (pf->precision - len + 1));
				ft_memset(zero,'0', pf->precision - len);

			}
		}
			pf->filling = ft_strjoinfree(zero, pf->filling);
		return;////////////////JANE START HERE
	}

}

void		print_int(t_pf *pf)///fill and print string
{
	int len;

	transform_int_precision(pf);

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
	else if (ft_strlen(pf->str_empty) && pf->precision == -1)
	{
		ft_putstr(pf->str_empty);
		pf->printed+=ft_strlen(pf->str_empty);
	}
}