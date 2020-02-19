/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:59:28 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 13:22:35 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*tmp;

	if (*src == '\0')
		dest[0] = '\0';
	tmp = dest;
	while (*src != '\0')
	{
		*tmp = *src;
		tmp = tmp + 1;
		src = src + 1;
	}
	*tmp = '\0';
	return (dest);
}
