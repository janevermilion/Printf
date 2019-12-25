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

void	upper_symb(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str) == 1)
			*str = ft_toupper(*str);
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
//	if (pf->precision == 0)
		pf->str_empty =ft_memalloc(sizeof(char) * (pf->width + 1));
//	else
//		pf->str_empty =ft_memalloc(sizeof(char) * (pf->precision + 1));

	if (pf->zero_filling == 1)
		ft_memset(pf->str_empty,'0', pf->width);
	else
		ft_memset(pf->str_empty,' ', pf->width);

}

void		print_all(t_pf *pf)
{
	if (pf->width != 0)
		zero_or_space_string(pf);
	if (pf->type == 'c')
		handle_char(pf);
	else if (pf->type == 's')
		handle_string(pf);
	else if (pf->type == 'p')
		handle_pointer(pf);
	else if (pf->type == 'd' || pf->type == 'i')
		handle_int(pf);
	else if (pf->type == 'o' || pf->type == 'u')
		handle_oct_and_unsigned(pf);
	else if (pf->type == 'x' || pf->type == 'X')
		handle_hex(pf);
	else if (pf->type == 'f')
		handle_float(pf);
	else if (pf->type == '%')
		handle_percent(pf);
	fill_and_print_string(pf);
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
		printf("!!!");
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
			//printf("\nf: %i", f);
			i+=f;
			f = check_width(&format[i], pf);
			i+=f;
			f = check_precision(&format[i], pf);
			i+=f;
			f = check_size_flag(&format[i], pf);
			i+=f;
			f = check_types(&format[i], pf);
			i+=f;
/*			printf(ANSI_COLOR_YELLOW "width: %i\n", pf->width);
			printf(ANSI_COLOR_YELLOW "align-left: %i\n", pf->align_left);
			printf(ANSI_COLOR_YELLOW "need sign: %i\n", pf->need_sign);
			printf(ANSI_COLOR_YELLOW "need space: %i\n", pf->need_spase);
			printf(ANSI_COLOR_YELLOW "need_format: %i\n", pf->need_format);
			printf(ANSI_COLOR_YELLOW "precision: %i\n", pf->precision);
			printf(ANSI_COLOR_YELLOW "type: %c\n", pf->type);
			printf(ANSI_COLOR_YELLOW "size_flag: %s\n", pf->size_flag);
			printf(ANSI_COLOR_YELLOW "length: %i\n\n" ANSI_COLOR_RESET, pf->length);*/
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




