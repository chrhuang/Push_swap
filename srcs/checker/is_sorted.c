/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:20:07 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/24 10:18:05 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	is_sorted(t_env *env)
{
	t_elem	*tmp;

	if (env == NULL)
		return (ERROR);
	if (env->a_start == NULL || env->b_start)
	{
		ft_putstr(KO_MSG);
		return (FAIL);
	}
	tmp = env->a_start;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
		{
			ft_putstr(KO_MSG);
			return (FAIL);
		}
		tmp = tmp->next;
	}
	ft_putstr(OK_MSG);
	return (SUCCESS);
}
