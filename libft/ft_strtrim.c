/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:42:57 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/08 15:40:23 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0' && (*s == ' ' || *s == '\t' || *s == '\n'))
		s = s + 1;
	if (s[i] == '\0')
		return (ft_strdup(""));
	while (s[i] != '\0')
		i = i + 1;
	i = i - 1;
	while (i != 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i = i - 1;
	if ((new = ft_strnew(i + 1)) == NULL)
		return (NULL);
	if ((new = ft_strncpy(new, s, i + 1)) == NULL)
		return (NULL);
	return (new);
}
