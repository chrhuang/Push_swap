/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:45:17 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 13:49:21 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *find)
{
	char	*tmp;
	char	*tmp1;

	if (ft_strcmp(find, "") == 0)
		return ((char *)str);
	while (*str != '\0')
	{
		if (*str == *find)
		{
			tmp = (char *)str;
			tmp1 = (char *)find;
			while (*tmp != '\0')
			{
				if ((*tmp != *tmp1 && *tmp1 == '\0') ||
					(*(tmp + 1) == '\0' && *(tmp1 + 1) == '\0'))
					return ((char *)str);
				else if (*tmp != *tmp1)
					break ;
				tmp = tmp + 1;
				tmp1 = tmp1 + 1;
			}
		}
		str = str + 1;
	}
	return (NULL);
}
