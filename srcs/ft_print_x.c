/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:47:02 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/15 20:03:10 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*ft_sharp(t_form f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

static int	recurs_hexa(t_form f, size_t n, size_t iteration)
{
	int		cnt;
	int		remainder;
	char	character;

	cnt = 0;
	if (n > 0 || (!iteration && (f.specifier != 'p' || !f.dot)))
	{
		remainder = n % 16;
		if (f.specifier != 'X')
			character = HXLOW[remainder];
		else
			character = HXUP[remainder];
		n /= 16;
		iteration = 1;
		cnt += recurs_hexa(f, n, iteration);
		cnt += ft_putchar_fd(character, 1);
	}
	return (cnt);
}

int	ft_print_x(t_form f, va_list ap)
{
	int				cnt;
	unsigned int	n;
	int				len;

	cnt = 0;
	n = va_arg(ap, unsigned int);
	len = ft_nbrlen(n, 16);
	if (!n && !f.precision && f.dot)
		len = 0;
	if (f.precision < 0 || f.precision < len || !f.dot)
		f.precision = len;
	if (f.shrp && n)
		f.wdth -= 2;
	cnt += ft_putstrn_fd(ft_sharp(f), 1, 2 * (f.shrp && f.zero && n));
	if (!f.minus && f.wdth > f.precision && (!f.dot || f.neg_prec) && f.zero)
		cnt += ft_putnchar_fd('0', 1, (f.wdth - f.precision));
	else if (!f.minus && f.wdth > f.precision)
		cnt += ft_putnchar_fd(' ', 1, (f.wdth - f.precision));
	cnt += ft_putstrn_fd(ft_sharp(f), 1, 2 * (f.shrp && !f.zero && n));
	cnt += ft_putnchar_fd('0', 1, (f.precision - len));
	if (len)
		cnt += recurs_hexa(f, n, n);
	if (f.minus && f.wdth > f.precision)
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	return (cnt);
}

int	ft_print_p(t_form f, va_list ap)
{
	int		cnt;
	size_t	n;
	int		len;

	cnt = 0;
	n = va_arg(ap, size_t);
	len = ft_nbrlen(n, 16);
	len *= !(!n && !f.precision && f.dot);
	if (f.precision < len || !f.dot)
		f.precision = len;
	cnt += write(1, "0x", 2 * f.zero);
	f.wdth -= 2;
	if (!f.minus && f.wdth > f.precision && !f.dot && f.zero)
		cnt += ft_putnchar_fd('0', 1, (f.wdth - f.precision));
	else if (!f.minus && f.wdth > f.precision)
		cnt += ft_putnchar_fd(' ', 1, (f.wdth - f.precision));
	cnt += write(1, "0x", 2 * !f.zero);
	cnt += ft_putnchar_fd('0', 1, (f.precision - len) * (n != 0));
	cnt += ft_putnchar_fd('0', 1, f.precision * (f.dot && !n));
	if (len)
		cnt += recurs_hexa(f, n, n);
	if (f.minus && f.wdth > f.precision)
		cnt += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	return (cnt);
}
