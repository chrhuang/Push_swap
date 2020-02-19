/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:41:50 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/14 14:57:16 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;
	int		i;

	tmp = (char *)dest;
	i = (int)n;
	if (dest < src)
		ft_memcpy(tmp, (void *)src, n);
	else if (i != 0 && dest >= src)
		while (i > 0)
		{
			i = i - 1;
			*(tmp + i) = *((char *)src + i);
		}
	return (dest);
}
