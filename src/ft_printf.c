/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:02:07 by jslave            #+#    #+#             */
/*   Updated: 2019/12/14 17:02:17 by jslave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *va_list	Тип, который используется для извлечения дополнительных параметров функции с переменным числом параметров
void va_start(va_list ap, paramN)	Макрос инициализирует ap для извлечения дополнительных аргументов, которые идут после переменной paramN. Параметр не должен быть объявлена как register, не может иметь типа массива или указателя на функцию.
void va_end(va_list ap)	Макрос необходим для нормального завершения работы функции, работает в паре с макросом va_start.
void va_copy(va_list dest, va_list src)	Макрос копирует src в dest. Поддерживается начиная со стандарта C++11
 *%[флаги][ширина][.точность][размер]тип
 */

/*
 *
 * c s p d i o u x X hh, h, l and ll %% #0-+
 */
int			find_step(int num)
{
	int res;

	res = 0;

	while (num)
	{
		res++;
		num = num / 10;
	}
	return (res);
}


int        convert_flags(const char *curr, t_pf *pf)
{
	int res;
	int width;
	int step;

	width = ft_atoi(curr + 1);
	pf->width = width;

	if ((res = check_percent(curr, pf) != 0))
	{
		return (res);
	}
	else if ((res = check_ints(curr, pf) != 0))
	{

		return (res);
	}
	else if ((res = check_chars(curr, pf) != 0))
	{

		return (res);
	}
	else if ((res = check_pointer(curr, pf) != 0))///in check chars
	{

		return (res);
	}
    return (0);
}

int       find_flag(const char *str, t_pf *pf)
{
    int flags;
    char *flag;

	flag = ft_strchr(FLAGS, *(str + 1));
    if (flag != NULL)//find flag
    {
    	pf->printed--;
        flags = convert_flags((str +1), pf);
        return(flags);
    }
    return (1);
}

int         ft_printf(const char *format, ...)
{
    t_pf *pf;
    int i;
    int perc_quan;
    perc_quan = 0;
    int f;

    i = 0;
    if ((pf = init_pf()) == NULL)
    	return (0);
    va_start(pf->ap, format);//NUL!!!!!
    while (format[i])
    {
       if (format[i] != '%')
	   {
		   ft_putchar(format[i]);
		   pf->printed++;
	   }
       else if (format[i] == '%')
       {
       		f = find_flag(&format[i], pf);
       		i+=f;
       		pf->printed+=f;
		   if (format[i] == 'h' && (format[i +1] == 'i' || format[i +1] == 'h'))
		   {
			   pf->printed--;
			   i++;
		   }
       }
       i++;
   }
    va_end(pf->ap);
    return (pf->printed);
}


