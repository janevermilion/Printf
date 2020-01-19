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

void        handle_int_zero(t_pf *pf)
{

    if (pf->precision > 1)
    {
        //free(pf->filling);
       pf->filling = ft_memalloc(pf->precision);
       ft_memset(pf->filling, '0', pf->precision);
    }
    else if (pf->precision <= 0 && pf->width > 1)
    {
        free(pf->filling);
        pf->filling = pf->str_empty;
        if (pf->align_left != 1)
        {
            pf->filling[pf->width - 1] = '0';
            if (pf->need_sign == 1 && pf->filling > 2 && pf->zero_filling != 1)
                pf->filling[pf->width - 2] = '+';
            else if (pf->need_sign == 1 && pf->filling > 2 && pf->zero_filling == 1)
                pf->filling[0] = '+';
        } else
        {

            if (pf->need_sign == 1 && pf->filling > 2)
            {
                pf->filling[0] = '+';
                pf->filling[1] = '0';
            } else
                pf->filling[0] = '0';
        }
    }

}



void        turn_width_more_prec(t_pf *pf, long long int num, int len)
{
    if (ft_strlen(pf->str_empty) > (size_t)len)
    {
        if (pf->align_left != 1)
            ft_memcpy(&pf->str_empty[pf->width - len], pf->filling, len);
        else
            ft_memcpy(pf->str_empty, pf->filling, len);
        free(pf->filling);
        pf->filling = pf->str_empty;//////
    }
    else if (num < 0 && ft_strlen(pf->str_empty) > (size_t)len)
    {
        pf->filling = ft_itoa_long_long(num*=-1);
        if (pf->align_left != 1)
            ft_memcpy(&pf->str_empty[pf->width - len], pf->filling, len);
        else
            ft_memcpy(pf->str_empty, pf->filling, len);
        pf->str_empty = ft_strjoinfree_s2("-", pf->str_empty);
        free(pf->filling);
        pf->filling = pf->str_empty;
    }
}

void        handle_int_precision_sec(t_pf *pf, long long int num)
{
    char *zero;
    int len;

    len = ft_strlen(pf->filling);
    if (pf->precision > len)
    {
        if (num < 0)
        {
            pf->filling = ft_itoa_long_long(num * -1);///FREEE
            len--;
        }
        zero = fill_zero_string(pf, len, num);
        pf->filling = ft_strjoinfree_both(zero, pf->filling);////FREEEEEE
        if (num < 0)
            put_sign(pf, num);
    }
}

void        handle_int_width_and_precision_sec(t_pf *pf, long long int num)
{
    int len;

    handle_int_precision_sec(pf, num);
    len = ft_strlen(pf->filling);
    if (pf->width > pf->precision )
    {
        if (pf->precision != 0 && pf->precision != -1)
            turn_width_more_prec(pf, num, len);
    }
    else
        handle_int_precision_sec(pf, num);
}

void        handle_int_width_sec(t_pf *pf, long long int num)
{
    int len;

    len = ft_strlen(pf->filling);
    if (pf->width > len)
    {
        if (num < 0)
            fill_empty_str_neg_num(pf, len, num);
        else
            fill_empty_str_pos_num(pf, len);
        free(pf->filling);///////////////
        pf->filling = pf->str_empty;
    }
}

void        handle_int_sign(t_pf *pf, long long int num)
{
    int i;
    char stop;
    int len;

    (void)num;
    len = (int)ft_strlen(pf->filling);
    i = 0;
   if (pf->precision > find_step(num) && pf->width > pf->precision)
   {
       stop = ' ';
       while (pf->filling[i] == stop && pf->filling[i] != '\0')
           i++;
       if ((i == len || i == 0) && pf->filling[pf->width -1] != stop)
           pf->filling = ft_strjoinfree_s2("+", pf->filling);
       else if ((i == len || i == 0) && pf->filling[pf->width -1] == stop)
       {
           i = pf->width -1;
           while (pf->filling[i] == stop)
               i--;
           while (i >= 0)
           {
               pf->filling[i + 1] = pf->filling[i];
               i--;
           }
           pf->filling[0] = '+';
       }
       else if (i < len && i)
       {
           if (pf->filling[0] == '0')
               pf->filling[0] = '+';
           else if (pf->filling[i - 1])
               pf->filling[i - 1] = '+';
       }
   }
   else if (pf->precision < find_step(num) && pf->width > pf->precision)
   {
       stop = ' ';
       while (pf->filling[i] == stop && pf->filling[i] != '\0')
           i++;
       if (i == 0 && pf->zero_filling == 1 && pf->width > find_step(num) && pf->align_left != 1)
           pf->filling[0] = '+';
       else if ((i == len || i == 0) && pf->filling[pf->width -1] != stop)
           pf->filling = ft_strjoinfree_s2("+", pf->filling);
       else if ((i == len || i == 0) && pf->filling[pf->width -1] == stop)
       {
           i = pf->width -1;
           while (pf->filling[i] == stop)
               i--;
           while (i >= 0)
           {
               pf->filling[i + 1] = pf->filling[i];
               i--;
           }
           pf->filling[0] = '+';
       }
       else if (i < len && i) {
           if (pf->filling[0] == '0')
               pf->filling[0] = '+';
           else if (pf->filling[i - 1])
               pf->filling[i - 1] = '+';
       }/////////////////////////////////////////////////////////////////HERE
   }
   else if ((pf->width == 0 && pf->precision < 0) || pf->width <= pf->precision)
       pf->filling = ft_strjoinfree_s2("+", pf->filling);

}
void        handle_int_space_sec(t_pf *pf, long long int num)
{
    int len;

    if (handle_max_and_min_long_long(pf) == 1)
        return;
    len = find_step((int)num);
    if (num >= 0 && pf->need_sign != 1)
    {
        if (pf->width <= len)
            pf->filling = ft_strjoinfree_s2(" ", pf->filling);////FREEEE
        if (pf->width > len + 1 && pf->align_left == 1)
            ft_str_overlap_copy(pf->filling);
        pf->filling[0] = ' ';
    }
}

void        print_int_second_edition(t_pf *pf, long long int num)
{
    if (num == 0)
        handle_int_zero(pf);
    else
    {
        if (pf->precision > 0 && pf->width > 0)
            handle_int_width_and_precision_sec(pf, num);
        else if (pf->precision < 0)
        {
            if (pf->width != 0)
                handle_int_width_sec(pf, num);
            else
                handle_int_precision_sec(pf, num);
        }
        else if (pf->precision > 0 && pf->precision > find_step(num))
            handle_int_precision_sec(pf, num);
        if (pf->need_sign == 1 && num >= 0)
            handle_int_sign(pf, num);
        if (pf->need_spase == 1 && pf->need_sign != 1)
            handle_int_space_sec(pf, num);

    }
    ft_putstr(pf->filling);
    pf->printed+=ft_strlen(pf->filling);
    }


int		    handle_int(t_pf *pf)
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
		num = (long int)va_arg(pf->ap,  long int);
	if (num == 0 && (pf->precision == -1 || pf->precision == 0))
	    pf->filling = "";
	else
	    pf->filling = ft_itoa_long_long(num);///itoa long long!
	//print_int(pf, num);
	print_int_second_edition(pf, num);
    return (pf->printed);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void		handle_int_precision(t_pf *pf)
{
	char *zero;
	int len;
	long long int num = ft_atoi_long_long(pf->filling);

	len = ft_strlen(pf->filling);
	if (pf->precision > len)
	{
		if (num < 0)
		{
			pf->filling = ft_itoa_long_long(num * -1);///FREEE
			len--;
		}
		zero = fill_zero_string(pf, len, num);
		pf->filling = ft_strjoinfree_both(zero, pf->filling);////FREEEEEE
		put_sign(pf, num);
	}
	else if (pf->need_sign == 1 && num >= 0)
		pf->filling = ft_strjoinfree_s2("+", pf->filling);///FREEEEE

}

void		handle_int_width(t_pf *pf)
{
	int len;
	long long int num;

    num = ft_atoi_long_long(pf->filling);
	if (pf->need_sign == 1 && num >= 0 && pf->zero_filling == 0)
		pf->filling = ft_strjoinfree_s2("+", pf->filling);//FREEEEE
	len = ft_strlen(pf->filling);
	if (pf->width > len)
	{
        if (num < 0)
            fill_empty_str_neg_num(pf, len, num);
        else
            fill_empty_str_pos_num(pf, len);
        free(pf->filling);///////////////
		pf->filling = pf->str_empty;
	}

}

void		handle_int_width_and_precision(t_pf *pf)
{
	int len;
    long long int num;

    num = ft_atoi_long_long(pf->filling);
	len = ft_strlen(pf->filling);
	if (pf->precision > len && pf->zero_filling == 1)
		ft_memset(pf->str_empty, ' ', pf->width);
	if (pf->width > pf->precision)
	{
	    if (pf->precision != 0 && pf->precision != -1)
        {
	        if (ft_strlen(pf->str_empty) > (size_t)len)
            {
	            if ( num >= 0)
                {
                    if (pf->align_left != 1)
                        ft_memcpy(&pf->str_empty[pf->width - len], pf->filling, len);
                    else
                        ft_memcpy(pf->str_empty, pf->filling, len);
                    free(pf->filling);
                    pf->filling = pf->str_empty;
                }
	            else
                {
                    if (pf->align_left != 1)
                        ft_memcpy(&pf->str_empty[pf->width - len], pf->filling, len);
                    else
                        ft_memcpy(pf->str_empty, pf->filling, len);
                    free(pf->filling);
                    pf->filling = pf->str_empty;
                }
                return;
            }
	        else if (num < 0 && ft_strlen(pf->str_empty) > (size_t)len)
            {
                pf->filling = ft_itoa_long_long(num*=-1);
                if (pf->zero_filling == 1)
                    ft_memset(pf->str_empty, '0', ft_strlen(pf->str_empty));
                if (pf->align_left != 1)
                    ft_memcpy(&pf->str_empty[pf->width - len], pf->filling, len);
                else
                    ft_memcpy(pf->str_empty, pf->filling, len);
                pf->str_empty = ft_strjoinfree_s2("-", pf->str_empty);
                free(pf->filling);
                pf->filling = pf->str_empty;
            }
        }
	}
}

void        ft_str_overlap_copy(char *str)
{
    char *tmp;
    size_t len;
    int i;
    int j;

    i = 1;
    j = 0;
    len = ft_strlen(str);

    tmp = ft_strnew(len);
    ft_memcpy(tmp, str, len);
    while (len-1)
    {
        str[i] = tmp[j];
        i++;
        j++;
        len--;
    }
    free(tmp);
}

int handle_max_and_min_long_long(t_pf *pf)
{
    if (ft_strequ(pf->filling, "9223372036854775807") == 1)
    {
        pf->filling = " 9223372036854775807";
        return (1);
    }
    else if (ft_strequ(pf->filling, "-9223372036854775807") == 1)
    {
        pf->filling = "-9223372036854775807";
        return (1);
    }
    return (0);
}

void        handle_int_space(t_pf *pf)
{
    int len;
    long long num;

    if (handle_max_and_min_long_long(pf) == 1)
        return;
    num = ft_atoi_long_long(pf->filling);
    len = find_step((int)num);
    if (num >= 0 && pf->need_sign != 1)
    {
        if (pf->width <= len)
            pf->filling = ft_strjoinfree_s2(" ", pf->filling);////FREEEE
        if (pf->width > len + 1 && pf->align_left == 1)
            ft_str_overlap_copy(pf->filling);
        pf->filling[0] = ' ';
    }
}

void		print_int(t_pf *pf, long long int num)
{
	if (pf->precision == -5 && pf->width == 0 && pf->align_left == 0 &&
	(pf->need_sign == 1 && num >= 0))
			pf->filling = ft_strjoinfree_s2("+", pf->filling);////FREEEEE
	if (pf->precision != -5)
		handle_int_precision(pf);
	else if (pf->width != 0 && pf->precision == -5)
		handle_int_width(pf);
	if (pf->width != 0 && pf->precision != -5)
	    handle_int_width_and_precision(pf);
	if (pf->need_spase == 1)
	    handle_int_space(pf);
	if (num == 0 && (pf->precision == 0 || pf->precision == -1) && pf->width >
	0 && pf->need_sign == 1)
    {
	    if(pf->align_left == 1)
	        pf->filling[0] = '+';
	    else
	        pf->filling[ft_strlen(pf->filling) - 1] = '+';
    }
	if (pf->precision == -5 && (size_t)pf->width <= ft_strlen(pf->filling) && pf->need_sign == 1 && ft_atoi_long_long(pf->filling) > 0 && pf->filling[0] != '+')
	    pf->filling = ft_strjoinfree_s2("+", pf->filling);
	ft_putstr(pf->filling);
	pf->printed+=ft_strlen(pf->filling);
}
