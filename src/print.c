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

void		print_char(t_pf *pf)
{
	char alpha;

	alpha = va_arg(pf->ap, int);
	if (pf->width != 0)
	{
		if (pf->align_left == 1)
			pf->str[0] = alpha;
		else
			pf->str[pf->width - 1] = alpha;
		ft_putstr(pf->str);
		pf->printed+=ft_strlen(pf->str);
	}
	else
	{
		ft_putchar(alpha);
		pf->printed+=1;
	}
};

void		fill_string(char *dst, char *src, t_pf *pf)
{
	int i;
	int diff;

	i = 0;
	if (pf->align_left == 1)
	{
		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		diff = ft_strlen(dst) - ft_strlen(src);
		while (src[i] != '\0')
		{
			dst[diff] = src[i];
			diff++;
			i++;
		}
	}
}


void		print_string(t_pf *pf)
{
	char *str;

	str = (char *)va_arg(pf->ap, char *);
	if (pf->width == 0 || (size_t)pf->width < ft_strlen(str))
	{
		ft_putstr(str);
		pf->printed+=ft_strlen(str);
	}
	else
	{
		fill_string(pf->str, str, pf);
		ft_putstr(pf->str);
		pf->printed+=ft_strlen(pf->str);
	}
};

void		print_pointer(t_pf *pf)
{
	unsigned long long int pnt;
	char *test;
	//int len;

	pnt = (unsigned long long int)va_arg(pf->ap, void *);
	test = ft_itoa_base(pnt, 16);
	test = ft_strjoin("0x", test);
	if (pf->width > (int)ft_strlen(test))
	{
		fill_string(pf->str, test, pf);///leak
		ft_putstr(pf->str);
	}
	else
		ft_putstr(test);
	pf->printed+= (ft_strlen(test));
};

void		print_int(t_pf *pf)
{
	(void)pf;
};

void		print_oct_and_unsigned(t_pf *pf)
{
	(void)pf;
};

void		print_hex(t_pf *pf)
{
	(void)pf;
};
void		print_float(t_pf *pf)
{
	(void)pf;
};

void		print_percent(t_pf *pf)
{
	if (pf->width != 0)
	{
		if (pf->align_left == 1)
		{
			pf->str[0] = '%';
		}
		else
			pf->str[ft_strlen(pf->str) -1] = '%';
		pf->printed+=ft_strlen(pf->str);
		ft_putstr(pf->str);
	}
	else
	{
		ft_putchar('%');
		pf->printed = 1;
	}
};
