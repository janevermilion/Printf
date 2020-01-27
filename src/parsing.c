/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:22:22 by jslave            #+#    #+#             */
/*   Updated: 2019/12/26 16:22:24 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	find_types(const char *str, char *parent)
{
	char *flag;
	char a;

	a = *str;
	flag = ft_strchr(parent, a);
	if (flag != NULL)
		return (1);
	return (0);
}

int 		check_types(const char *curr, t_pf *pf)
{
	char a = *curr;
	if(!*curr)
	    return (0);
	if (find_types(curr, TYPES) == 1)
		pf->type = a;
	return (0);
}

int		zero_or_space_string(t_pf *pf)
{
	pf->str_empty =ft_memalloc(sizeof(char) * (pf->width + 1));
	if (pf->str_empty == NULL)
		return (-1);
	if (pf->type != '%')
	{
		if (pf->zero_filling == 1 && (find_types(&pf->type, INT_TYPES) == 1 &&
		pf->align_left != 1))
        {
		    if (pf->precision > pf->width || pf->precision == -5)
                ft_memset(pf->str_empty,'0', pf->width);
		    else
                ft_memset(pf->str_empty,' ', pf->width);
        }
		else
			ft_memset(pf->str_empty,' ', pf->width);
	}
	else
	{
		if (pf->zero_filling == 1 && pf->align_left != 1)
			ft_memset(pf->str_empty,'0', pf->width);
		else
			ft_memset(pf->str_empty,' ', pf->width);
	}
	return (1);
}

int			check_size_flag(const char *curr, t_pf *pf)
{
	if (*curr == 'h' && *(curr + 1) == 'h')
	{
		pf->size_flag = ft_strdup("hh");
		return (2);
	}
	else if (*curr == 'h')
	{
		pf->size_flag = ft_strdup("h");
		return (1);
	}
	else if (*curr == 'l' && *(curr +1) == 'l')
	{
		pf->size_flag = ft_strdup("ll");
		return (2);
	}
	else if (*curr == 'l')
	{
		pf->size_flag = ft_strdup("l");
		return (1);
	}
	else if (*curr == 'L')
	{
		pf->size_flag = ft_strdup("L");
		return (1);
	}
	return (0);
}
