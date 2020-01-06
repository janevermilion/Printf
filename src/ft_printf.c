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
			/*printf(ANSI_COLOR_YELLOW "\nwidth: %i\n", pf->width);
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




