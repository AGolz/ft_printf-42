/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:50:50 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/18 00:01:23 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char			*ptr;

	ptr = NULL;
	while (*str)
	{
		if (*str == (char)ch)
			ptr = (char *)str;
		str++;
	}
	if ((char)ch == *str)
		return ((char *)str);
	return (ptr);
}
