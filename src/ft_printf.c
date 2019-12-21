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

void	lower_symb(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str) == 1)
			*str = ft_tolower(*str);
		str++;
	}
}

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
		if (pf->align_left != 1 && *curr == '-')
		{
			pf->align_left = 1;
			return (1);
		}
		else if (pf->need_sign!= 1 && *curr == '+')
		{
			pf->need_sign = 1;
			return (1);
		}
		else if (pf->need_sign != 1 && *curr == ' ')
		{
			pf->need_spase = 1;
			return (1);
		}
		else if (pf->need_format != 1 && *curr == '#')
		{
			pf->need_format = 1;
			return (1);
		}
		else if (pf->zero_filling != 1 && *curr == '0')
		{
			pf->zero_filling = 1;
			return (1);
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
	pf->str =ft_memalloc(sizeof(char) * (pf->width + 1));
	if (pf->zero_filling == 1)
		ft_memset(pf->str,'0', pf->width);
	else
		ft_memset(pf->str,' ', pf->width);
}

void		print_all(t_pf *pf)
{
	if (pf->width != 0)
		zero_or_space_string(pf);
	if (pf->type == 'c')
		print_char(pf);
	else if (pf->type == 's')
		print_string(pf);
	else if (pf->type == 'p')
		print_pointer(pf);
	else if (pf->type == 'd' || pf->type == 'i')
		print_int(pf);
	else if (pf->type == 'o' || pf->type == 'u')
		print_oct_and_unsigned(pf);
	else if (pf->type == 'x' || pf->type == 'X')
		print_hex(pf);
	else if (pf->type == 'f')
		print_float(pf);
	else if (pf->type == '%')
		print_percent(pf);
}

int			check_size_flag(const char *curr, t_pf *pf)
{
	if (*curr == 'h')
	{
		pf->size_flag = "h";
		return (1);
	}
	else if (*curr == 'h' && *(curr + 1) == 'h')
	{
		pf->size_flag = "hh";
		return (2);
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


int         ft_printf(const char *format, ...)
{
	t_pf *pf;
	int i;
	int f;

	i = 0;
	if ((pf = init_pf()) == NULL)
		return (0);
	va_start(pf->ap, format);//NUL!!!!!
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			pf->printed++;
		}
		else if (format[i] == '%')
		{
			f = check_flags(&format[++i], pf);
			i+=f;
			f = check_width(&format[i], pf);
			i+=f;
			f = check_precision(&format[i], pf);
			i+=f;
			f = check_size_flag(&format[i], pf);
			i+=f;
			f = check_types(&format[i], pf);
			i+=f;
			print_all(pf);
			zero_pf(pf);
		}
		i++;
	}
	va_end(pf->ap);
	i = pf->printed;
	free(pf);
	return (i);
}




