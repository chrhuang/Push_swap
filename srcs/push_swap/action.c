/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:09:09 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 20:45:26 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int			add_action(t_env *env, t_elem *new)
{
	if (new == NULL)
		return (ERROR);
	env->action_size++;
	if (env->action_start == NULL)
	{
		env->action_start = new;
		env->action_end = new;
		return (SUCCESS);
	}
	new->prev = env->action_end;
	env->action_end->next = new;
	env->action_end = new;
	return (SUCCESS);
}

static int	opti_ra(t_env *env, t_elem *current)
{
	t_elem *tmp;

	if (current->value != RA)
		return (FAIL);
	tmp = current;
	while (tmp != NULL && (tmp->value == RA || tmp->value == RR))
		tmp = tmp->next;
	if (tmp == NULL)
		return (FAIL);
	if (!(tmp->value == RB))
		return (FAIL);
	current->value = RR;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	env->action_size--;
	free(tmp);
	return (SUCCESS);
}

static int	opti_rra(t_env *env, t_elem *current)
{
	t_elem *tmp;

	if (current->value != RRA)
		return (FAIL);
	tmp = current;
	while (tmp != NULL && (tmp->value == RRA || tmp->value == RRR))
		tmp = tmp->next;
	if (tmp == NULL)
		return (FAIL);
	if (!(tmp->value == RRB))
		return (FAIL);
	current->value = RRR;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	env->action_size--;
	free(tmp);
	return (SUCCESS);
}

int			opti_action(t_env *env)
{
	t_elem	*tmp;

	if (env == NULL)
		return (ERROR);
	tmp = env->action_start;
	while (tmp != NULL)
	{
		if (opti_ra(env, tmp) == SUCCESS)
		{
			tmp = env->action_start;
			continue;
		}
		if (opti_rra(env, tmp) == SUCCESS)
		{
			tmp = env->action_start;
			continue;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}
