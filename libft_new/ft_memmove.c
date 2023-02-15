/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:50:16 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/18 00:00:21 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*str_1;
	const unsigned char	*str_2;

	str_1 = (unsigned char *)dst;
	str_2 = (const unsigned char *)src;
	i = 0;
	if (!src && !dst)
		return (NULL);
	while (i < n)
	{
		if (dst > src)
			str_1[n - i - 1] = str_2[n - i - 1];
		else
			str_1[i] = str_2[i];
		i++;
	}
	return (dst);
}
