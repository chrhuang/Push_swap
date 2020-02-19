/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:51:59 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/14 09:20:39 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	charac;
	int				i;

	tmp = (unsigned char *)str;
	charac = (unsigned char)c;
	i = 0;
	while (n != 0)
	{
		if (tmp[i] == charac)
			return ((void *)tmp + i);
		i = i + 1;
		n = n - 1;
	}
	return (NULL);
}
