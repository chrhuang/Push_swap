/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:07:57 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 13:38:53 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;

	if (s == NULL)
		return (NULL);
	while (*s != '\0' && start != 0)
	{
		start = start - 1;
		s = s + 1;
	}
	if (*s == '\0')
		return (NULL);
	if ((tmp = ft_strnew(len)) == NULL)
		return (NULL);
	tmp = ft_strncpy(tmp, s, len);
	tmp[len] = '\0';
	return (tmp);
}
