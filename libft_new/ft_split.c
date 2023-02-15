/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:49:14 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/18 03:43:11 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_get_strs(char const *s, const char ch)
{
	unsigned int	i;
	unsigned int	strs;

	if (!s[0])
		return (0);
	i = 0;
	strs = 0;
	while (s[i] && s[i] == ch)
		i++;
	while (s[i])
	{
		if (s[i] == ch)
		{
			strs++;
			while (s[i] && s[i] == ch)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != ch)
		strs++;
	return (strs);
}

static void	ft_get_nw_strs(char **nw_str, unsigned int *len_nw_str, \
								const char ch)
{
	unsigned int	i;

	*nw_str += *len_nw_str;
	*len_nw_str = 0;
	i = 0;
	while (**nw_str && **nw_str == ch)
		(*nw_str)++;
	while ((*nw_str)[i])
	{
		if ((*nw_str)[i] == ch)
			return ;
		(*len_nw_str)++;
		i++;
	}	
}

static char	**ft_free_split(char **arr)
{
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	char			*nw_str;
	unsigned int	len_nw_str;
	unsigned int	strs;
	unsigned int	i;

	if (!s)
		return (NULL);
	strs = ft_get_strs(s, c);
	arr = malloc((strs + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	nw_str = (char *)s;
	len_nw_str = 0;
	while (i < strs)
	{
		ft_get_nw_strs(&nw_str, &len_nw_str, c);
		arr[i] = ft_calloc(len_nw_str + 1, sizeof(char));
		if (!arr[i])
			return (ft_free_split(arr));
		ft_strlcpy(arr[i++], nw_str, len_nw_str + 1);
	}
	arr[i] = NULL;
	return (arr);
}
