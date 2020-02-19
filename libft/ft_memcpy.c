/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:03:26 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 13:05:17 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, void *s2, size_t n)
{
	char	*str1;
	char	*str2;

	if (n == 0)
		return (s1);
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (n != 0)
	{
		*str1 = *str2;
		str1 = str1 + 1;
		str2 = str2 + 1;
		n = n - 1;
	}
	return (s1);
}
