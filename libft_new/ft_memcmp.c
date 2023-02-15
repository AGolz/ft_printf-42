/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:50:07 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/19 22:29:40 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr_1, const void *arr_2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;

	if (n == 0)
		return (0);
	ptr_1 = (unsigned char *)arr_1;
	ptr_2 = (unsigned char *)arr_2;
	i = 0;
	while (*ptr_1 == *ptr_2 && ++i < n)
	{
		ptr_1++;
		ptr_2++;
	}
	return ((int)(*ptr_1 - *ptr_2));
}
