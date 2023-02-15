/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:50:42 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/18 00:01:12 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str_1, const char *str_2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *str_1 == *str_2 && *str_1 != '\0' && *str_2 != '\0')
	{
		str_1++;
		str_2++;
	}
	return ((unsigned char)*str_1 - (unsigned char)*str_2);
}
