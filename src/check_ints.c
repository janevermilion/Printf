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

int		check_ints(const char *curr, t_pf *pf)
{
	unsigned long long int qual;
	unsigned int qual_u;
	char *result;

	qual = 0;
	if (*curr == 'i' || *curr == 'd')
	{
		qual = check_sp(curr, pf);
		pf->printed+=(int)qual;
		ft_putnbr(va_arg(pf->ap, int));
		return ((int)qual + 1);
	}
	if (*curr == 'o')
	{
		qual = (unsigned long long int)va_arg(pf->ap, void *);
		result = ft_itoa_base(qual, 8);
		ft_putstr(result);
		pf->printed+=ft_strlen(result);
		return (ft_strlen(result));
	}
	if (*curr == 'u')///peredelat!
	{
		qual_u = (unsigned int)va_arg(pf->ap, unsigned int);
		result = ft_itoa(qual_u);
		ft_putstr(result);
		pf->printed+=ft_strlen(result);
		return (ft_strlen(result));
	}

	return (0);
}
