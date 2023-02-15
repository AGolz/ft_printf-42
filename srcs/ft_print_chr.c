/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:29:25 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/15 20:02:35 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_s(t_form f, va_list ap)
{
	char	*string;
	int		cnt;

	cnt = 0;
	string = va_arg(ap, char *);
	if (!string)
		string = "(null)";
	if (!f.dot || f.precision > (int)ft_strlen(string) || f.precision < 0)
		f.precision = ft_strlen(string);
	if (!f.minus && f.wdth > f.precision && f.zero && (!f.dot || f.neg_prec))
		cnt += ft_putnchar_fd('0', 1, f.wdth - f.precision);
	else if (!f.minus && f.wdth - f.precision > 0)
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	cnt += ft_putstrn_fd(string, 1, f.precision);
	if (f.minus && f.wdth - f.precision > 0)
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	return (cnt);
}

int	ft_print_c(t_form f, va_list ap)
{
	char	c;
	int		cnt;

	cnt = 0;
	if (f.specifier == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	f.precision = 1;
	if (!f.minus && f.zero)
		cnt += ft_putnchar_fd('0', 1, f.wdth - f.precision);
	else if (!f.minus && f.wdth > f.precision)
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	cnt += ft_putchar_fd(c, 1);
	if (f.minus && f.wdth - f.precision > 0)
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	return (cnt);
}
