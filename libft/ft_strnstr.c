/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:16:09 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 14:41:37 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(const char *str, const char *find, size_t n)
{
	char	*tmp;
	char	*tmp1;

	tmp = (char *)str;
	tmp1 = (char *)find;
	while (*tmp != '\0' && n != 0)
	{
		if (*tmp != *tmp1 && *tmp1 == '\0')
			return (0);
		else if (*tmp != *tmp1)
			break ;
		tmp = tmp + 1;
		tmp1 = tmp1 + 1;
		n = n - 1;
	}
	if (*tmp == *tmp1 && *tmp == '\0' && *tmp1 == '\0')
		return (0);
	else if (n == 0 && *tmp1 == '\0')
		return (0);
	return (-1);
}

char			*ft_strnstr(const char *str, const char *find, size_t n)
{
	if (ft_strcmp(find, "") == 0)
		return ((char *)str);
	while (*str != '\0' && n != 0)
	{
		if ((*str == *find) && check(str, find, n) == 0)
			return ((char *)str);
		str = str + 1;
		n = n - 1;
	}
	return (NULL);
}
