/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:43:40 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 14:49:43 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)str1;
	tmp2 = (unsigned char *)str2;
	while (n != 0)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1 = tmp1 + 1;
		tmp2 = tmp2 + 1;
		n = n - 1;
	}
	if (n == 0)
		return (0);
	if (*tmp1 == 0 && *tmp2 != 0)
		return (-(*tmp2));
	else if (*tmp2 == 0 && *tmp1 != 0)
		return (*tmp1);
	return (0);
}
