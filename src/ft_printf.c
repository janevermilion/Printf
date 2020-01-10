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

void		print_all(t_pf *pf)
{
	if (pf->width != 0)
		if (zero_or_space_string(pf) == -1)
			return;
	if (pf->type == 'c')
		handle_char(pf);
	else if (pf->type == 's')
		handle_string(pf);
	else if (pf->type == 'p')
		handle_pointer(pf);
	else if (pf->type == 'd' || pf->type == 'i')
		handle_int(pf);
	else if (pf->type == 'o')
		handle_oct(pf);
	else if (pf->type == 'u')
	    handle_unsigned(pf);
	else if (pf->type == 'x' || pf->type == 'X')
		handle_hex(pf);
	else if (pf->type == 'f')
		handle_float(pf);
	else if (pf->type == '%')
		handle_percent(pf);
}

int 		read_args(t_pf *pf, const char *format)
{
	int i;
	i = 0;

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			pf->printed++;
		}
		else if (format[i] == '%')
		{
			i++;
			i+=check_flags(&format[i], pf);
			i+=check_width(&format[i], pf);
			i+=check_precision(&format[i], pf);
			i+=check_size_flag(&format[i], pf);
			i+=check_types(&format[i], pf);
			/*printf(ANSI_COLOR_YELLOW "\nwidth: %i\n", pf->width);
			printf(ANSI_COLOR_YELLOW "align-left: %i\n", pf->align_left);
			printf(ANSI_COLOR_YELLOW "need sign: %i\n", pf->need_sign);
			printf(ANSI_COLOR_YELLOW "need space: %i\n", pf->need_spase);
			printf(ANSI_COLOR_YELLOW "need_format: %i\n", pf->need_format);
			printf(ANSI_COLOR_YELLOW "precision: %i\n", pf->precision);
			printf(ANSI_COLOR_YELLOW "type: %c\n", pf->type);
			printf(ANSI_COLOR_YELLOW "size_flag: %s\n", pf->size_flag);
			printf(ANSI_COLOR_YELLOW "length: %i\n\n" ANSI_COLOR_RESET, pf->length);*/
			print_all(pf);//Need to return success\fail?
			zero_pf(pf);
		}
		i++;
	}
	return (i);
}

int         ft_printf(const char *format, ...)
{
	t_pf *pf;
	int i;

	if ((pf = init_pf()) == NULL)
		return (0);
	va_start(pf->ap, format);//NUL!!!!!
	if (read_args(pf, format) < 0)
		return (-1);
	va_end(pf->ap);
	i = pf->printed;
	free(pf);
	return (i);
}




