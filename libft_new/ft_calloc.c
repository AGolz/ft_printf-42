/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:49:37 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/19 21:44:10 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char	*dst;
	size_t	i;
	size_t	sum;

	sum = number * size;
	if (sum > __INT_MAX__ || number == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	dst = malloc(sum);
	if (!dst)
		return (NULL);
	i = 0;
	while (sum--)
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}
