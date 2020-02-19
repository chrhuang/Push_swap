/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:15:04 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 13:20:22 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*tmp;

	tmp = dest;
	while (*tmp != '\0')
		tmp = tmp + 1;
	while (*src != '\0' && n != 0)
	{
		*tmp = *src;
		tmp = tmp + 1;
		src = src + 1;
		n = n - 1;
	}
	*tmp = '\0';
	return (dest);
}
