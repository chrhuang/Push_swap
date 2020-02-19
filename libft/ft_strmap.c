/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:42:01 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/08 15:23:29 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((tmp = ft_strdup((char *)s)) == NULL)
		return (NULL);
	while (tmp[i] != '\0')
	{
		tmp[i] = (f)(tmp[i]);
		i = i + 1;
	}
	return (tmp);
}
