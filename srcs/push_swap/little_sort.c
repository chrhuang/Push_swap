/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:06:07 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 23:25:17 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	three_sort_b(t_env *env)
{
	t_elem	*tmp;
	t_elem	*next;

	tmp = env->b_start;
	next = env->b_start->next;
	if (tmp->value > next->value && tmp->value > next->next->value)
	{
		do_rrb(env);
		do_sb(env);
	}
	else if (tmp->value < next->value && tmp->value > next->next->value)
		do_sb(env);
	else if (tmp->value > next->value && tmp->value < next->next->value)
		do_rrb(env);
	else if (tmp->value < next->value && tmp->value < next->next->value &&
	next->value < next->next->value)
	{
		do_sb(env);
		do_rrb(env);
	}
	else if (tmp->value < next->value && tmp->value < next->next->value &&
	next->value > next->next->value)
		do_rb(env);
	return (SUCCESS);
}

static int	three_sort_a(t_env *env)
{
	t_elem	*tmp;
	t_elem	*next;

	tmp = env->a_start;
	next = env->a_start->next;
	if (tmp->value < next->value && tmp->value < next->next->value)
	{
		do_rra(env);
		do_sa(env);
	}
	else if (tmp->value > next->value && tmp->value < next->next->value)
		do_sa(env);
	else if (tmp->value < next->value && tmp->value > next->next->value)
		do_rra(env);
	else if (tmp->value > next->value && tmp->value > next->next->value &&
	next->value > next->next->value)
	{
		do_sa(env);
		do_rra(env);
	}
	else if (tmp->value > next->value && tmp->value > next->next->value &&
	next->value < next->next->value)
		do_ra(env);
	return (SUCCESS);
}

static int	*search_max(t_env *env)
{
	t_elem	*tmp;
	int		*max;

	if ((max = malloc(sizeof(int) * 3)) == NULL)
		return (NULL);
	max[0] = env->a_max;
	tmp = env->a_start;
	max[1] = env->a_min;
	while (tmp != NULL)
	{
		if (max[1] < tmp->value && tmp->value != max[0])
			max[1] = tmp->value;
		tmp = tmp->next;
	}
	tmp = env->a_start;
	max[2] = env->a_min;
	while (tmp != NULL)
	{
		if (max[2] < tmp->value && tmp->value != max[0] && tmp->value != max[1])
			max[2] = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

static int	do_little_sort(t_env *env)
{
	int	*max;

	if (env == NULL)
		return (ERROR);
	if ((max = search_max(env)) == NULL)
		return (ERROR);
	while (env->a_size > 3)
		env->a_start->value == max[0] || env->a_start->value == max[1] ||
		env->a_start->value == max[2] ? do_ra(env) : do_pb(env);
	if (!(env->a_start->value < env->a_start->next->value &&
		env->a_start->next->value < env->a_start->next->next->value))
		three_sort_a(env);
	if (env->b_size == 2)
		env->b_start->value < env->b_start->next->value ? do_sb(env) : 0;
	else if (env->b_size == 3)
		if (!(env->b_start->value > env->b_start->next->value &&
		env->b_start->next->value > env->b_start->next->next->value))
			three_sort_b(env);
	while (env->b_size > 0)
		do_pa(env);
	free(max);
	return (SUCCESS);
}

int			little_sort(t_env *env)
{
	if (env == NULL)
		return (ERROR);
	if (is_sorted(env) == SUCCESS)
		return (SUCCESS);
	if (env->a_size == 1)
		return (SUCCESS);
	else if (env->a_size == 2)
	{
		env->a_start->value > env->a_start->next->value ? do_sa(env) : 0;
		return (SUCCESS);
	}
	else if (env->a_size == 3)
		return (three_sort_a(env));
	else
		return (do_little_sort(env));
	return (SUCCESS);
}
