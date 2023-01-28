/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:31:58 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/28 15:44:01 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	int cnt;
	va_list ap;
	char *first;
	
	cnt = 0; 
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			first = (char *)str;
			if (*(++str))
				cnt += ft_pars((char *)str, ap);
		}
	}
}

int ft_print_format(t_form f, va_list ap)
{
	int n;

	n = 0;
	if (f.spec == 'c' || f.spec == '%')
		n = ft_print_c(f, ap);
	if (f.spec == 's')
		n = ft_print_s(f, ap);
	if (f.spec == 'd' || f.spec == 'i' || f.spec == 'u')
		n = ft_print_diu();
	if (f.spec == 'X' || f.spec == 'x')
		n = ft_print_x(f, ap);
	if (f.spec == 'p')
		n = ft_print_p(f, ap);
	return (n);
}