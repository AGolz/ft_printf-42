/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:49:20 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/17 20:53:48 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *buf, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buf;
	while (count -- > 0)
		*ptr++ = 0;
}
