/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:09:39 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 13:19:53 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*tmp;

	tmp = dest;
	while (*tmp != '\0')
		tmp = tmp + 1;
	while (*src != '\0')
	{
		*tmp = *src;
		tmp = tmp + 1;
		src = src + 1;
	}
	*tmp = '\0';
	return (dest);
}
