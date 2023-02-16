/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:57:41 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/16 15:06:47 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_format	ft_pars_bonus(char *str, t_format f)
{
	while (*str != '.' && !ft_strchr (SPEC, *str))
	{
		if (*str == '+')
			f.plus = 1;
		if (*str == ' ')
			f.space = 1;
		if (*str == '#')
			f.shrp = 1;
		str++;
	}
	return (f);
}

static t_format	ft_pars_wdth(char *str, va_list	ap, t_format f)
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

static t_format	ft_pars_precis(char *str, va_list ap, t_format f)
{
	int	spcf;

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
	t_format	new_format;

	new_format = ft_pars_wdth(str, ap, ft_new_form());
	new_format = ft_pars_bonus(str, new_format);
	while (!ft_strchr(SPEC, *str) && *str != '.')
		str++;
	if (*str == '.' && !new_format.specifier)
	{
		new_format.dot = 1;
		new_format = ft_pars_precis(str++, ap, new_format);
		while (!ft_strchr(SPEC, *str))
			str++;
	}
	if (new_format.wdth < 0)
	{
		new_format.minus = 1;
		new_format.wdth *= -1;
	}
	new_format.specifier = *str;
	new_format.neg_prec = new_format.precision < 0;
	return (ft_print_form(new_format, ap));
}
