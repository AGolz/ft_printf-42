/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:47:02 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/09 21:58:46 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sharp(t_form f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

static int	ft_recursive_hex(t_form f, size_t n, size_t iteration)
{
	int		count;
	int		remainder;
	char	character;

	count = 0;
	if (n > 0 || (!iteration && (f.specifier != 'p' || !f.dot)))
	{
		remainder = n % 16;
		if (f.specifier != 'X')
			character = HXLOW[remainder];
		else
			character = HXUP[remainder];
		n /= 16;
		iteration = 1;
		count += ft_recursive_hex(f, n, iteration);
		count += ft_putchar_fd(character, 1);
	}
	return (count);
}

int	ft_print_x(t_form f, va_list ap)
{
	int				count;
	unsigned int	n;
	int				len;

	count = 0;
	n = va_arg(ap, unsigned int);
	len = ft_nbrlen(n, 16);
	if (!n && !f.precision && f.dot)
		len = 0;
	if (f.precision < 0 || f.precision < len || !f.dot)
		f.precision = len;
	if (f.sharp && n)
		f.wdth -= 2;
	count += ft_putstrn_fd(ft_sharp(f), 1, 2 * (f.sharp && f.zero && n));
	if (!f.minus && f.wdth > f.precision && (!f.dot || f.neg_prec) && f.zero)
		count += ft_putnchar_fd('0', 1, (f.wdth - f.precision));
	else if (!f.minus && f.wdth > f.precision)
		count += ft_putnchar_fd(' ', 1, (f.wdth - f.precision));
	count += ft_putstrn_fd(ft_sharp(f), 1, 2 * (f.sharp && !f.zero && n));
	count += ft_putnchar_fd('0', 1, (f.precision - len));
	if (len)
		count += ft_recursive_hex(f, n, n);
	if (f.minus && f.wdth > f.precision)
		count += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	return (count);
}

int	ft_print_p(t_form f, va_list ap)
{
	int		count;
	size_t	n;
	int		len;

	count = 0;
	n = va_arg(ap, size_t);
	len = ft_nbrlen(n, 16);
	len *= !(!n && !f.precision && f.dot);
	if (f.precision < len || !f.dot)
		f.precision = len;
	count += write(1, "0x", 2 * f.zero);
	f.wdth -= 2;
	if (!f.minus && f.wdth > f.precision && !f.dot && f.zero)
		count += ft_putnchar_fd('0', 1, (f.wdth - f.precision));
	else if (!f.minus && f.wdth > f.precision)
		count += ft_putnchar_fd(' ', 1, (f.wdth - f.precision));
	count += write(1, "0x", 2 * !f.zero);
	count += ft_putnchar_fd('0', 1, (f.precision - len) * (n != 0));
	count += ft_putnchar_fd('0', 1, f.precision * (f.dot && !n));
	if (len)
		count += ft_recursive_hex(f, n, n);
	if (f.minus && f.wdth > f.precision)
		count += ft_putnchar_fd(' ', 1, f.wdth - f.precision);
	return (count);
}