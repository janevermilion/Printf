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

int         ft_printf(const char *format, ...)
{
    va_list args;
    int test;

    va_start(args, format);
    if(format[1] == 'i')
    {
        test = va_arg(args,int);
        ft_putnbr(test);
    }
    va_end(args);
    return (0);
}

int         main()
{
    int cat = 165;
    ft_printf("%i", cat);
    return (0);
}