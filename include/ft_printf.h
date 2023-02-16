/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:31:54 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/16 15:05:55 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>

# define SPEC "csdiupxX%"
# define HXLOW "0123456789abcdef"
# define HXUP "0123456789ABCDEF" 

typedef struct s_format
{
	int		minus;
	int		plus;
	int		wdth;
	int		precision;
	int		neg_prec;
	int		zero;
	int		dot;
	int		space;
	int		shrp;
	char	specifier;
}						t_format;

int			ft_printf(const char *str, ...);
int			ft_pars(char *str, va_list ap);
int			ft_print_c(t_format f, va_list ap);
int			ft_print_s(t_format f, va_list ap);
int			ft_print_diu(t_format f, va_list ap);
int			ft_print_x(t_format f, va_list ap);
int			ft_print_p(t_format f, va_list ap);
int			ft_print_form(t_format f, va_list ap);
t_format	ft_new_form(void);

#endif
