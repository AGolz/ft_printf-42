/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:31:54 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/28 15:38:23 by emaksimo         ###   ########.fr       */
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
	int		prec;
	int		neg_prec;
	int		zero;
	int		dot;
	int		space;
	int 	shrp;
	char	format;
}						t_form;

# define SPEC "csdiupxX%"

#endif 
