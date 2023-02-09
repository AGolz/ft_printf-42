/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:12:48 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/09 21:55:29 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_form ft_pars_bs (char *str, t_form f)
{
	while (*str != '.' && !ft_strchr (SPEC, *str))
	{
		if (*str == '+')
			f.plus = 1;
		if (*str == ' ')
			f.space = 1;
		if (*str == '#')
			f.sharp = 1;
		str++;
	}
	return (f);
}

static t_form	ft_pars_wdth(char* str, va_list	ap, t_form f)
{
	int	spcf;
	
	spcf = 0;
	while (*str != '.' && !ft_strchr(SPEC, *str))
	{
		if (*str == '-')
			f.minus = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			f.zero = 1;
		else if (((*str > '0' && *str <= '9') || *str == '*') && !spcf)
		{
			if (*str == '*')
				f.wdth = va_arg(ap, int);
			else
				f.wdth = ft_atoi(str);
			spcf = 1;
		}
		str++;
	}
	return (f);
}

static t_form ft_pars_precis(char *str, va_list ap, t_form f)
{
	int spcf;
	
	spcf = 0;
	while (!ft_strchr(SPEC, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !spcf)
		{
			if (*str == '*')
				f.precision = va_arg(ap, int);
			else
				f.precision = ft_atoi(str);
			spcf = 1;
		}
		str++;
	}
	return (f);
}

int	ft_pars(char *str, va_list ap)
{
	t_form nw_frt;
	
	nw_frt = ft_pars_wdth(str, ap, ft_new_format());
	nw_frt = ft_pars_bs(str, nw_frt);
	while (!ft_strchr(SPEC, *str) && *str != '.')
		str++;
	if (*str == '.' && !nw_frt.specifier)
	{
		nw_frt.dot = 1;
		nw_frt = ft_pars_precis(str++, ap, nw_frt);
		while (!ft_strchr(SPEC, *str))
			str++;
	}
	if (nw_frt.wdth < 0)
	{
		nw_frt.minus = 1;
		nw_frt.wdth *= -1;
	}
	nw_frt.specifier = *str;
	nw_frt.neg_prec = nw_frt.precision < 0;
	return (ft_print_format(nw_frt, ap));
}