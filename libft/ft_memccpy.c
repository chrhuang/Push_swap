/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:32:26 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 14:53:22 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp1;

	tmp = (unsigned char *)dest;
	tmp1 = (unsigned char *)src;
	while (n != 0)
	{
		*tmp = *tmp1;
		if (*tmp == (unsigned char)c)
		{
			tmp = tmp + 1;
			return (tmp);
		}
		tmp = tmp + 1;
		tmp1 = tmp1 + 1;
		n = n - 1;
	}
	return (NULL);
}
