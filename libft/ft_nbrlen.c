/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:21:49 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/15 19:45:38 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(unsigned long nbr, unsigned long base)
{
	unsigned long	len;

	len = 0;
	if (!base)
		base = 10;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}
