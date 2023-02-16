/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:50:12 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/18 01:50:59 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str_1;
	const unsigned char	*str_2;

	str_1 = (unsigned char *)dst;
	str_2 = (unsigned char *)src;
	if (!n || dst == src)
		return (dst);
	while (n --)
	{
		*str_1++ = *str_2++;
	}
	return (dst);
}
