/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:14:20 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/09 20:16:05 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_print_s(t_form f, va_list ap)

{
	char *string;
	int  count;
	int  has_malloc;
	
	count = 0;
	has_malloc = 0;
	string = va_arg(ap, char *);
	if (!string)
	{
		string = malloc(sizeof(char) * 7);
		has_malloc = 1;
		ft_strlcpy(string, "(null)", 7);
	}
	if (!f.dot || f.precision > (int)ft_strlen(string) || f.precision < 0)
		f.precision = ft_strlen(string);
	if (!f.minus && f.wdth > f.precision && f.zero && (!f.dot || f.neg_prec))
		count += ft_putnchar_fd('0', 1, f.wdth - f.precision);
	else if (!f.minus && f.wdth - f.precision > 0)
		count += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	count += ft_putstrn_fd(string, 1, f.precision);
	if (f.minus && f.wdth - f.precision > 0)
		count += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	if (has_malloc)
		free(string);
	return (count);
}

int ft_print_c(t_form f, va_list ap)
{
	char c;
	int cnt; 

	cnt = 0;
	if (f.specifier == 'c')
		c = va_arg(ap, int);
	else 
		c = '%';
	f.precision = 1;
	if (!f.minus && f.zero)
		cnt += ft_putnchar_fd('0', 1, f.wdth - f.precision);
	else if (!f.minus && f.wdth > f.precision )
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	cnt += ft_putchar_fd(c, 1);
	if (f.minus && f.wdth - f.precision > 0)
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	return (cnt);
		
	 	
}