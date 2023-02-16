/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:50:21 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/17 23:12:11 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buf;
	while (count--)
		*(ptr++) = (unsigned char)ch;
	return (buf);
}
