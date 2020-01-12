//
// Created by Jamar Slave on 10/01/2020.
//

#include "ft_printf.h"

void		handle_int_precision_oct(t_pf *pf)
{
    char *zero;
    int len;
    unsigned long long int num = ft_atoi_long_long_uns(pf->filling);

    len = ft_strlen(pf->filling);
    if (pf->precision > len)
    {
        zero = fill_zero_string(pf, len, num);
        pf->filling = ft_strjoin(zero, pf->filling);////FREEEEEE
        put_sign(pf, num);
    }
    else if (pf->need_sign == 1)
        pf->filling = ft_strjoin("+", pf->filling);///FREEEEE
}

void		handle_int_width_oct(t_pf *pf)
{
    int len;
    unsigned long long int num;

    num = ft_atoi_long_long_uns(pf->filling);
    if (pf->need_sign == 1 && pf->zero_filling == 0)
        pf->filling = ft_strjoin("+", pf->filling);//FREEEEE
    len = ft_strlen(pf->filling);
    if (pf->width > len)
    {
        fill_empty_str_pos_num(pf, len);
        free(pf->filling);
        pf->filling = pf->str_empty;
    }
}

void        handle_int_space_oct(t_pf *pf)
{
    int len;
    unsigned long long num;

    if (handle_max_and_min_long_long(pf) == 1)
        return;
    num = ft_atoi_long_long_uns(pf->filling);
    len = find_step((int)num);
    if (pf->need_sign != 1)
    {
        if (pf->width <= len)
            pf->filling = ft_strjoin(" ", pf->filling);////FREEEE
        if (pf->width > len + 1 && pf->align_left == 1)
            ft_str_overlap_copy(pf->filling);
        pf->filling[0] = ' ';
    }
}

int         handle_zero_oct(t_pf *pf)
{
    unsigned long long int num;
    char *zero;

    num = ft_atoi_long_long_uns(pf->filling);
    if (num == 0)
    {
        if (pf->width <= 0 && pf->precision < 1)
        {
            if (pf->precision == 0 || pf->precision == -1)
                pf->filling = "";
            if (pf->width <= 0 && pf->need_format == 1 && pf->precision != -5)
                pf->filling = ft_strjoin("0", pf->filling);//FREEEE
        }
        else if(pf->width > 1 && pf->precision <= 0)
        {
            free(pf->filling);
            pf->filling = pf->str_empty;
            if (pf->align_left == 1 && pf->precision != 0 && pf->precision != -1)
                pf->str_empty[0] = '0';
            else if (pf->align_left !=1 && pf->precision != 0 && pf->precision != -1)
                pf->str_empty[pf->width-1] = '0';
            else if (pf->align_left == 1 && ((pf->precision == 0 || pf->precision == -1)) && pf->need_format == 1)
                pf->str_empty[0] = '0';
            else if (pf->align_left !=1 && ((pf->precision == 0 || pf->precision == -1) && pf->need_format == 1))
                pf->str_empty[pf->width-1] = '0';
            else if (pf->align_left == 1 && (pf->precision == -5))
                pf->str_empty[0] = '0';
            else if (pf->align_left !=1 && (pf->precision == -5))
                pf->str_empty[pf->width-1] = '0';
        }
        else if (pf->precision > 1)
        {
            zero = fill_zero_string(pf, 1, 0);
            pf->filling = ft_strjoin(zero, pf->filling);////FREEEEEE
            if (pf->width > pf->precision)
                handle_int_width_and_precision(pf);
        }

        return (1);
    }
    return (0);
}

void		print_int_oct(t_pf *pf)
{
    unsigned long long int num;

    if (handle_zero_oct(pf) == 0)
    {
        num = ft_atoi_long_long_uns(pf->filling);
        if (pf->precision == -5 && pf->width == 0 && pf->align_left == 0 &&
            (pf->need_sign == 1))
            pf->filling = ft_strjoin("+", pf->filling);////FREEEEE
        if (pf->precision != -5)
            handle_int_precision_oct(pf);
        if (pf->width != 0 && pf->precision == -5)
            handle_int_width_oct(pf);
        else if (pf->width != 0 && pf->precision != -5)
            handle_int_width_and_precision(pf);
        if (pf->need_spase == 1)
            handle_int_space_oct(pf);
    }
    ft_putstr(pf->filling);
    pf->printed+=ft_strlen(pf->filling);
}

void		handle_oct(t_pf *pf)
{
    unsigned long long int num;
    num = 0;

    if (pf->size_flag == NULL)
        num = (unsigned int)va_arg(pf->ap, unsigned int);
    else if (ft_strequ(pf->size_flag, "hh") == 1)
        num = (unsigned char)va_arg(pf->ap, unsigned int);
    else if (ft_strequ(pf->size_flag, "h") == 1)
        num = (unsigned short)va_arg(pf->ap, unsigned int);
    else if (ft_strequ(pf->size_flag, "ll") == 1)
        num = (unsigned long long int)va_arg(pf->ap, unsigned long long int);
    else if (ft_strequ(pf->size_flag, "l") == 1)
        num = (unsigned long int)va_arg(pf->ap,  unsigned long int);
    pf->filling = ft_itoa_base_unsigned(num, 8);
    if (pf->need_format == 1 && num)
        pf->filling = ft_strjoin("0", pf->filling);//FREEEE
    print_int_oct(pf);
};