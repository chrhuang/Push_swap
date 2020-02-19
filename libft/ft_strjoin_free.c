/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:35:46 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/29 14:42:19 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, t_pos pos)
{
	char	*new;

	if (s1 == NULL)
	{
		new = ft_strdup(s2);
		if (pos.y == 1)
			ft_memdel((void **)&s2);
		return (new);
	}
	if (s2 == NULL)
		return (NULL);
	if ((new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 2)) == NULL)
		return (NULL);
	if ((new = ft_strcat(new, s1)) == NULL)
		return (NULL);
	if ((new = ft_strcat(new, s2)) == NULL)
		return (NULL);
	if (pos.x == 1)
		ft_memdel((void **)&s1);
	if (pos.y == 1)
		ft_memdel((void **)&s2);
	return (new);
}
