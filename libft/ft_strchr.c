/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:37:35 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 13:20:44 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp != '\0')
	{
		if (*tmp == c)
			return (tmp);
		tmp = tmp + 1;
	}
	if (c == '\0' && *tmp == '\0')
		return (tmp);
	return (NULL);
}
