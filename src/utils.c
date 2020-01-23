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

t_pf 		*init_pf(t_pf *pf)
{
	//t_pf *pf;

    pf = (t_pf *)malloc(sizeof(t_pf));
	if(!pf)
        return(NULL);
	pf->width = 0;
	pf->printed = 0;
	pf->align_left = 0;
	pf->need_sign = 0;
	pf->need_spase = 0;
	pf->need_format = 0;
	pf->zero_filling = 0;
	pf->precision = -5;
	pf->type = '\0';
    pf->size_flag = ft_strdup("");
    pf->str_empty = ft_strdup("");
    pf->filling = ft_strdup("");
    pf->length = 0;
	return (pf);
}

void		zero_pf(t_pf *pf)
{
	pf->width = 0;
	pf->align_left = 0;
	pf->need_sign = 0;
	pf->need_spase = 0;
	pf->need_format = 0;
	pf->zero_filling = 0;
	pf->precision = -5;
	pf->type = '\0';
	free(pf->size_flag);
	free(pf->str_empty);
	free(pf->filling);
    //pf->size_flag = ft_strdup("");
   //pf->str_empty = ft_strdup("");
   //pf->filling = ft_strdup("");
	pf->length = 0;
}

void        free_pf(t_pf *pf)
{
    if (pf->size_flag)
        free(pf->size_flag);
    if (pf->str_empty)
        free(pf->str_empty);
    if(pf->filling)
        free(pf->filling);
    free(pf);
}

void        upper_symb(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str) == 1)
			*str = ft_toupper(*str);
		str++;
	}
}