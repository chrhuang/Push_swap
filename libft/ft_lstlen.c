/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:05:16 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/14 10:20:44 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(const t_list *list)
{
	size_t	i;

	i = 0;
	if (list == NULL)
		return (0);
	while (list != NULL)
	{
		list = list->next;
		i = i + 1;
	}
	return (i);
}
