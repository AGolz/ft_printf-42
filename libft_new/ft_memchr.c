/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:50:01 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/17 23:58:21 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char *)arr;
	i = 0;
	while (i < n && str[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void *)(str + i));
}
