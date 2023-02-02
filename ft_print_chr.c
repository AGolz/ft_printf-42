/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:29:25 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/02 22:18:58 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_s(t_form f, va_list ap)
{
	char *string;
	int cnt;

	cnt = 0;
	string = va_arg(ap, char *);
	if (!string)
		string = "(null)";
	if(!f.dot || f.precis > (int)ft_strlen(string) || f.precis < 0)
		f.precis = ft_strlen(string);
	if (!f.minus && f.wdth > f.precis && f.zero && (!f.dot || f.neg_prec))
		cnt += ft_putnchar_fd('0', 1, f.wdth - f.precis);
	else if (f.minus && f.wdth - f.precis > 0)
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precis);
	if (f.minus && f.wdth - f.precis > 0)
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precis);
	return (cnt);
}

int ft_print_c(t_form f, va_list ap)
{
	char c;
	int cnt; 

	cnt = 0;
	if (f.spec == 'c')
		c = va_arg(ap, int);
	else 
		c = '%';
	f.precis = 1;
	if (!f.minus && f.zero)
		cnt += ft_putnchar_fd('0', 1, f.wdth - f.precis);
	else if (!f.minus && f.wdth > f.precis )
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precis);
	cnt += ft_putchar_fd(c, 1);
	if (f.minus && f.wdth - f.precis > 0)
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precis);
	return (cnt);
		
	 	
}