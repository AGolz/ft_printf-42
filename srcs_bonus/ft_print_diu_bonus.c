/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:15:05 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/16 15:03:22 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static char	plus(t_format f)
{
	if (f.plus)
		return ('+');
	return ('-');
}

static int	ft_print_nbr(t_format f, char *nbr, int len, int neg)
{
	int	c;

	c = 0;
	f.wdth -= (f.space && !neg && !f.plus && f.wdth);
	if (neg || f.plus)
		c += ft_putnchar_fd(plus(f), 1, f.zero && (!f.dot || f.neg_prec));
	else if (f.space)
		c += ft_putnchar_fd(' ', 1, f.zero && !f.dot);
	if (!f.minus && f.wdth > f.precision && (!f.dot || f.neg_prec) && f.zero)
		c += ft_putnchar_fd('0', 1, f.wdth - f.precision - neg - f.plus);
	else if (!f.minus && f.wdth > f.precision)
		c += ft_putnchar_fd(' ', 1, f.wdth - f.precision - neg - f.plus);
	if ((neg || f.plus) && ft_strncmp(nbr, "-2147483648", 12))
		c += ft_putnchar_fd(plus(f), 1, !f.zero || (f.dot && !f.neg_prec));
	else if (f.space && ft_strncmp(nbr, "-2147483648", 12))
		c += ft_putnchar_fd(' ', 1, !f.zero || f.dot);
	c += ft_putnchar_fd('0', 1, f.precision - len);
	c += write(1, nbr, len);
	if (f.minus && f.wdth > f.precision)
		c += ft_putnchar_fd(' ', 1, f.wdth - f.precision - neg - f.plus);
	return (c);
}

int	ft_print_diu(t_format f, va_list ap)
{
	char	*nbr;
	int		n;
	int		c;
	int		len;
	int		neg;

	c = 0;
	n = va_arg(ap, int);
	neg = (n < 0 && n != INT_MIN && f.specifier != 'u');
	if (neg)
		f.plus = 0;
	if (n < 0 && f.specifier != 'u')
		n *= -1;
	if (n < 0 && f.specifier == 'u')
		nbr = ft_uitoa((unsigned)n);
	else
		nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !f.precision && f.dot)
		len = 0;
	if (f.precision < len || !f.dot)
		f.precision = len;
	c += ft_print_nbr(f, nbr, len, neg);
	free(nbr);
	return (c);
}
