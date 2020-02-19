/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:16:37 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 13:17:38 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	is_sorted(t_env *env)
{
	t_elem	*tmp;

	if (env == NULL)
		return (ERROR);
	if (env->b_size != 0)
		return (FAIL);
	tmp = env->a_start;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (FAIL);
		tmp = tmp->next;
	}
	return (SUCCESS);
}
