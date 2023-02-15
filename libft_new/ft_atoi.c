/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:49:10 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/18 03:36:08 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		negative;
	long	i;

	i = 0;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str - '0');
		if (i > 2147483648 && negative == -1)
			return (0);
		str++;
	}
	return (negative * (int)i);
}
