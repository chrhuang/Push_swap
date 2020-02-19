/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:03:15 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 14:24:27 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*tmp;

	tmp = (char *)dest;
	while (n != 0)
	{
		*tmp = *src;
		tmp = tmp + 1;
		if (*src != '\0')
			src = src + 1;
		n = n - 1;
	}
	if (n != 0)
		*tmp = '\0';
	return (dest);
}
