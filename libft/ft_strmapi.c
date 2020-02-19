/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:46:27 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/08 15:23:46 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*tmp;
	unsigned int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	if ((tmp = ft_strdup((char *)s)) == NULL)
		return (NULL);
	while (tmp[i] != '\0')
	{
		tmp[i] = (f)(i, tmp[i]);
		i = i + 1;
	}
	return (tmp);
}
