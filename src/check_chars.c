/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:56:21 by jslave            #+#    #+#             */
/*   Updated: 2019/12/17 16:56:23 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_chars(const char *curr, t_pf *pf)
{
	int quan;
	char *test2;


	quan = 0;
	if (*curr == 'c')
	{
		char test = va_arg(pf->ap, int);
		ft_putchar(test);
		pf->printed+=1;
		return (1);
	}
	else if (*curr == 's')
	{
		test2 = (char *)va_arg(pf->ap, char *);
		ft_putstr(test2);
		pf->printed+=ft_strlen(test2);
		return (ft_strlen(test2));
	}
	else if (*curr == 'h' && *(curr + 1) == 'h')
	{

	}
	return (0);
}

int 	check_pointer(const char *curr, t_pf *pf)
{
	(void)pf;
	unsigned long long int pnt;
	if (*curr == 'p')
	{
		pnt = (unsigned long long int)va_arg(pf->ap, void *);
		char *test;
		test = ft_itoa_base(pnt, 16);
		ft_printf("0x");
		ft_putstr(test);
		pf->printed+= (ft_strlen(test) + 2);
		return (ft_strlen(test) + 2);
	}

	return (0);
}//0x7fff5c4ffa48

