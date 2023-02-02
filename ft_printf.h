/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:31:54 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/02 21:14:20 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

#include "../Libft/libft.h"

#include <stdarg.h>

typedef struct s_form
{
	int		minus;
	int		plus;
	int		wdth;
	int		precis;
	int		neg_prec;
	int		zero;
	int		dot;
	int		space;
	int 	shrp;
	char	spec;
}						t_form;


# define SPECIFIER "csdiupxX%"
# define HEXALOW "0123456789abcdef"
# define HEXAUP "0123456789ABCDEF"
# define INT_MIN -2147483648
# define UNIT_MAX 4294967295                                                                                                                                                                                          

int ft_printf(const char *str, ...);
int	ft_pars(char *str, va_list ap);
int ft_print_c(t_form f, va_list ap);
int ft_print_s(t_form f, va_list ap);
int	ft_print_diu(t_form f, va_list ap);
int	ft_print_x(t_form f, va_list ap);
int	ft_print_p(t_form f, va_list ap);
int ft_print_format(t_form f, va_list ap);
t_form	ft_new_format(void);

#endif

