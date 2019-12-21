/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:28:01 by jslave            #+#    #+#             */
/*   Updated: 2019/12/17 16:28:03 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*
short	check_short(long long int num)
{
	if (num < SHRT_MIN || num > SHRT_MAX)
		return (0);
	return (1);
}

int		check_ints(const char *curr, t_pf *pf)
{
	unsigned long long int qual;
	unsigned int qual_u;
	long long int qual2;

	char *result;

	if (*curr == 'i' || *curr == 'd')
	{
		qual = (unsigned long long int)va_arg(pf->ap, void *);
		result = ft_itoa_base(qual, 10);
		ft_putstr(result);
		pf->printed+=ft_strlen(result);
		return (ft_strlen(result));
	}
	else if (*curr == 'o')
	{
		qual = (unsigned long long int)va_arg(pf->ap, void *);
		result = ft_itoa_base(qual, 8);
		ft_putstr(result);
		pf->printed+=ft_strlen(result);
		return (ft_strlen(result));
	}
	else if (*curr == 'u' || *curr == 'o')///peredelat!
	{
		qual_u = (long long int)va_arg(pf->ap, void *);
		if (*curr == 'u')
			result = ft_itoa_long_long(qual_u);
		else
			result = ft_itoa_base(qual_u, 8);
		ft_putstr(result);
		pf->printed+=ft_strlen(result);
		return (ft_strlen(result));
	}
	else if (*curr == 'x' || *curr == 'X')
	{
		qual = (unsigned long long int)va_arg(pf->ap, unsigned long long int);
		result = ft_itoa_base(qual, 16);
		if (*curr == 'x')
			lower_symb(result);
		ft_putstr(result);
		pf->printed+=ft_strlen(result);
		return (ft_strlen(result));
	}
	else if(*curr == 'h' && *(curr +1) == 'i')
	{
		qual2 = (long long int)va_arg(pf->ap, void *);
		if ((check_short(qual2) == 1))
		{
			result = ft_itoa_base(qual2, 10);
			ft_putstr(result);
			pf->printed+=ft_strlen(result);
			return (ft_strlen(result));
		}
	}

	return (0);
}
*/