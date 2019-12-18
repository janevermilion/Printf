/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:54:20 by jslave            #+#    #+#             */
/*   Updated: 2019/12/17 15:54:21 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf 		*init_pf()
{
	t_pf *pf;

	pf = malloc(sizeof(t_pf));
	pf->spaces = 0;
	pf->printed = 0;
	return (pf);
}

int		check_sp(const char *curr, t_pf *pf)
{
	int num_of_spaces;
	int i;
	int result;


	num_of_spaces = ft_atoi(curr);
	i = num_of_spaces;
	pf->spaces = num_of_spaces;
	pf->printed+=num_of_spaces;
	result = 0;
	while (num_of_spaces--)
	{
		pf->printed++;
		ft_putchar(32);
	}
	while (i % 10)
	{
		result++;
		i/=10;
	}
	return (result);
}

int			check_percent(const char *curr)
{
	if (*curr == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}