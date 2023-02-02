/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:47:02 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/02 21:14:20 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_shrp(t_form f)
{
	if (f.spec == 'X')
		return ("0X");
	return ("0x");
}

static int	ft_recursive_hex(t_form f, size_t n, size_t iteration)
{
	int		count;
	int		remainder;
	char	character;

	count = 0;
	if (n > 0 || (!iteration && (f.spec != 'p' || !f.dot)))
	{
		remainder = n % 16;
		if (f.spec != 'X')
			character = HEXALOW[remainder];
		else
			character = HEXAUP[remainder];
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
	if (!n && !f.precis && f.dot)
		len = 0;
	if (f.precis < 0 || f.precis < len || !f.dot)
		f.precis = len;
	if (f.shrp && n)
		f.wdth -= 2;
	count += ft_putstrn_fd(ft_shrp(f), 1, 2 * (f.shrp && f.zero && n));
	if (!f.minus && f.wdth > f.precis && (!f.dot || f.neg_prec) && f.zero)
		count += ft_putnchar_fd('0', 1, (f.wdth - f.precis));
	else if (!f.minus && f.wdth > f.precis)
		count += ft_putnchar_fd(' ', 1, (f.wdth - f.precis));
	count += ft_putstrn_fd(ft_shrp(f), 1, 2 * (f.shrp && !f.zero && n));
	count += ft_putnchar_fd('0', 1, (f.precis - len));
	if (len)
		count += ft_recursive_hex(f, n, n);
	if (f.minus && f.wdth > f.precis)
		count += ft_putnchar_fd(' ', 1, f.wdth - f.precis);
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
	len *= !(!n && !f.precis && f.dot);
	if (f.precis < len || !f.dot)
		f.precis = len;
	count += write(1, "0x", 2 * f.zero);
	f.wdth -= 2;
	if (!f.minus && f.wdth > f.precis && !f.dot && f.zero)
		count += ft_putnchar_fd('0', 1, (f.wdth - f.precis));
	else if (!f.minus && f.wdth > f.precis)
		count += ft_putnchar_fd(' ', 1, (f.wdth - f.precis));
	count += write(1, "0x", 2 * !f.zero);
	count += ft_putnchar_fd('0', 1, (f.precis - len) * (n != 0));
	count += ft_putnchar_fd('0', 1, f.precis * (f.dot && !n));
	if (len)
		count += ft_recursive_hex(f, n, n);
	if (f.minus && f.wdth > f.precis)
		count += ft_putnchar_fd(' ', 1, f.wdth - f.precis);
	return (count);
}