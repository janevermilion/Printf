#include "ft_printf.h"
#include "limits.h"

void	printf_fill_3(t_pf *pf)
{
	if (pf->align_left == 1 && pf->need_sign == 1)
	{
		pf->filling = ft_strjoinfree_s1(pf->filling,\
		spaces(' ', pf->width -\
		(int)ft_strlen(pf->filling) - pf->need_sign * (pf->num > 0) *\
		pf->zero_filling - (pf->num < 0) * !(pf->flag)));
	}
	else if (pf->align_left != 1 && pf->need_sign != pf->need_spase &&\
	pf->need_sign == 0)
	{
		pf->filling = ft_strjoinfree_s2(spaces(' ',\
		pf->width - (int)ft_strlen(pf->filling) - pf->need_spase *\
		!(pf->flag)), pf->filling);
	}
	else
		printf_fill_4(pf);
}

void	printf_fill_2(t_pf *pf)
{
	if (pf->align_left == 1 && pf->need_sign == 0)
	{
		pf->filling = ft_strjoinfree_s1(pf->filling,\
		spaces(' ', pf->width - (int)ft_strlen(pf->filling) -\
		(int)(pf->zero_filling * (pf->num < 0)) - pf->need_spase *\
		(pf->num > 0)));
	}
	else
		printf_fill_3(pf);
	if ((pf->need_spase == 1) && (pf->num > 0) && (pf->need_sign == 0))
		pf->filling = ft_strjoinfree_s2(" ", pf->filling);
	if (pf->need_sign == 1 && pf->num > 0 && pf->zero_filling == 1)
		pf->filling = ft_strjoinfree_s2("+", pf->filling);
	if (pf->num < 0 && pf->zero_filling == 1)
		pf->filling = ft_strjoinfree_s2("-", pf->filling);
}

void	printf_float_3(long double tmp, t_pf *pf)
{
	unsigned long long	left;
	long double			tmp1;
	char				*src;

	if ((tmp < 0))
		tmp1 = -tmp;
	else
		tmp1 = tmp;
	left = (unsigned long long)tmp1;
	tmp1 -= left;
	src = ft_strnew(ft_strlen(ft_itoa_long_long(left)));
	src = ft_itoa_long_long_uns(left);
	pf->filling = ft_strjoinfree_s2(pf->filling, src);
	if ((pf->flag == 1) && (pf->need_format == 1))
		pf->filling = ft_strjoinfree_s1(pf->filling, ".");
	pf->flag = 0;
	pf->filling = ft_strjoinfree_s2(pf->filling,\
	ft_ftos_sec(ft_round(tmp1, ft_power(0.1,\
	pf->precision)), pf->precision));
	sign_2(pf);
	printf_fill_2(pf);
}

void	print_float(t_pf *pf, long double num)
{
	long double	tmp;
	int			len;

	pf->flag = 0;
	if (pf->precision == 0)
		pf->flag = 1;
	else if (pf->precision < 0)
		pf->precision = 6;
	tmp = num;
	len = ft_length(tmp, pf->precision);
	if (len > pf->width)
		printf_float_2(tmp, len, pf);
	else
		printf_float_3(tmp, pf);
	pf->printed += ft_strlen(pf->filling);
	ft_putstr(pf->filling);
}

int		dbl_2(t_pf *pf)
{
	if (pf->num == DBL_MAX && pf->precision == -5)
	{
		ft_putstr(MAX_DBL);
		pf->printed += 316;
		return (1);
	}
	else if (pf->num == DBL_MAX && pf->precision != -5)
	{
		ft_putstr(MAX_DBL);
		pf->printed += 313;
		return (1);
	}
	return (0);
}