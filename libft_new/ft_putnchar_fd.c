/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:30:00 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/15 19:47:05 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnchar_fd(char c, int fd, int n)
{
	int	ret;

	ret = 0;
	while (n-- > 0)
		ret += (int)write(fd, &c, 1);
	return (ret);
}
