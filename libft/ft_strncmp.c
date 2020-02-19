/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:31:37 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 13:59:54 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && n != 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i = i + 1;
		n = n - 1;
	}
	if (s1[i] == 0 && s2[i] != 0 && n != 0)
		return (-s2[i]);
	else if (s2[i] == 0 && s1[i] != 0 && n != 0)
		return (s1[i]);
	return (0);
}
