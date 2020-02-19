/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:03:51 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 22:14:03 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

char	search_rotate(t_elem *start, t_elem *end, int value)
{
	t_elem			*tmp;
	unsigned int	front;
	unsigned int	back;

	front = 0;
	back = 1;
	tmp = start;
	while (tmp != NULL)
	{
		if (tmp->value == value)
			break ;
		front++;
		tmp = tmp->next;
	}
	tmp = end;
	while (tmp != NULL)
	{
		if (tmp->value == value)
			break ;
		back++;
		tmp = tmp->prev;
	}
	return (front < back ? 1 : -1);
}
