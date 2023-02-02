/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:47:25 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/02 22:19:31 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	plus(t_form f)
{
	if (f.plus)
		return ('+');
	return ('-');
}

static int	ft_print_nbr(t_form f, char *nbr, int len, int neg)
{
	int	c;

	c = 0;
	f.wdth -= (f.space && !neg && !f.plus && f.wdth);
	if (neg || f.plus)
		c += ft_putnchar_fd(plus(f), 1, f.zero && (!f.dot || f.neg_prec));
	else if (f.space)
		c += ft_putnchar_fd(' ', 1, f.zero && !f.dot);
	if (!f.minus && f.wdth > f.precis && (!f.dot || f.neg_prec) && f.zero)
		c += ft_putnchar_fd('0', 1, f.wdth - f.precis - neg - f.plus);
	else if (!f.minus && f.wdth > f.precis)
		c += ft_putnchar_fd(' ', 1, f.wdth - f.precis - neg - f.plus);
	if (neg || f.plus)
		c += ft_putnchar_fd(plus(f), 1, !f.zero || (f.dot && !f.neg_prec));
	else if (f.space)
		c += ft_putnchar_fd(' ', 1, !f.zero || f.dot);
	c += ft_putnchar_fd('0', 1, f.precis - len);
	c += write(1, nbr, len);
	if (f.minus && f.wdth > f.precis)
		c += ft_putnchar_fd(' ', 1, f.wdth - f.precis - neg - f.plus);
	return (c);
}

int	ft_print_diu(t_form f, va_list ap)
{
	char	*nbr;
	int		n;
	int		c;
	int		len;
	int		neg;

	c = 0;
	n = va_arg(ap, int);
	neg = (n < 0 && n != INT_MIN && f.spec != 'u');
	if (neg)
		f.plus = 0;
	if (n < 0 && f.spec != 'u')
		n *= -1;
	if (n < 0 && f.spec == 'u')
		nbr = ft_itoa((unsigned)n);
	else
		nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !f.precis && f.dot)
		len = 0;
	if (f.precis < len || !f.dot)
		f.precis = len;
	c += ft_print_nbr(f, nbr, len, neg);
	free(nbr);
	return (c);
}