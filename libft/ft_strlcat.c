/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:50:31 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/20 00:15:22 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			res;

	i = 0;
	res = 0;
	if (!size)
		return (ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	while (src[res] && (i + res + 1) < size)
	{
		dst[i + res] = src[res];
		res++;
	}
	if (i < size)
		dst[i + res] = '\0';
	return (i + ft_strlen(src));
}
