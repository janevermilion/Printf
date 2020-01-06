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

int 	find_types(const char *str)
{
	char *flag;
	char a;

	a = *str;

	flag = ft_strchr(TYPES, a);
	if (flag != NULL)//find flag
		return (1);
	return (0);
}

int		check_flags(const char *curr, t_pf *pf)
{
	if (*curr != '\0' && find_types(curr) == 0)//проверить не начался ли тип
	{
		if (*curr == '-')
		{
			pf->align_left = 1;
			return (check_flags((curr + 1), pf) + 1);
		}
		else if (*curr == '+')
		{
			pf->need_sign = 1;
			return (check_flags((curr + 1), pf) + 1);
		}
		else if (*curr == ' ')
		{
			pf->need_spase = 1;
			return (check_flags((curr + 1), pf) + 1);
		}
		else if (*curr == '#')
		{
			pf->need_format = 1;
			return (check_flags((curr + 1), pf) + 1);
		}
		else if (*curr == '0')
		{
			pf->zero_filling = 1;
			return (check_flags((curr + 1), pf) + 1);
		}
	}
	else if (*curr == '%')
		return (0);
	return (0);
}

int 		check_types(const char *curr, t_pf *pf)
{
	char a = *curr;
	if (find_types(curr) == 1)
		pf->type = a;//////////////////////////////////////////////////////////////////////////
	return (0);
}

void		zero_or_space_string(t_pf *pf)
{
	pf->str_empty =ft_memalloc(sizeof(char) * (pf->width + 1));
	if (pf->type != '%')
	{
		if (pf->zero_filling == 1)
			ft_memset(pf->str_empty,'0', pf->width);
		else
			ft_memset(pf->str_empty,' ', pf->width);
	}
	else///for percent
	{
		if (pf->zero_filling == 1 && pf->align_left != 1)
			ft_memset(pf->str_empty,'0', pf->width);
		else
			ft_memset(pf->str_empty,' ', pf->width);
	}

}

int			check_size_flag(const char *curr, t_pf *pf)
{
	if (*curr == 'h' && *(curr + 1) == 'h')
	{
		pf->size_flag = "hh";
		return (2);
	}
	else if (*curr == 'h')
	{
		pf->size_flag = "h";
		return (1);
	}
	else if (*curr == 'l' && *(curr +1) == 'l')
	{
		pf->size_flag = "ll";
		return (2);
	}
	else if (*curr == 'l')
	{
		pf->size_flag = "l";
		return (1);
	}
	return (0);
}
