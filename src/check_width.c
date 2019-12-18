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

int			check_width(const char *curr, t_pf *pf)
{
	int qual;
	qual = 0;

	if (*curr >= '0' && *curr <= '9')
	{
		qual = check_sp(curr, pf);
		pf->printed+=qual;

	}
	return (qual);
}