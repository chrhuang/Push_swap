/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:22:01 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 11:22:17 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	search_min(t_elem *list)
{
	int	min;

	if (list == NULL)
		return (0);
	min = list->value;
	while (list != NULL)
	{
		if (min > list->value)
			min = list->value;
		list = list->next;
	}
	return (min);
}

static int	search_max(t_elem *list)
{
	int	max;

	if (list == NULL)
		return (0);
	max = list->value;
	while (list != NULL)
	{
		if (max < list->value)
			max = list->value;
		list = list->next;
	}
	return (max);
}

int			search_min_max(t_env *env)
{
	env->a_min = search_min(env->a_start);
	env->a_max = search_max(env->a_start);
	env->b_min = search_min(env->b_start);
	env->b_max = search_max(env->b_start);
	return (SUCCESS);
}
