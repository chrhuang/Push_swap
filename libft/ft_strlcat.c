/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:21:58 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/07 13:36:17 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tmp;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < n)
		i = i + 1;
	tmp = i;
	if (i < n)
	{
		while (src[j] != '\0' && j < n && i <= n - 2)
		{
			dest[i] = src[j];
			j = j + 1;
			i = i + 1;
		}
		dest[i] = '\0';
	}
	while (*src != '\0')
	{
		src = src + 1;
		tmp = tmp + 1;
	}
	return (tmp);
}
