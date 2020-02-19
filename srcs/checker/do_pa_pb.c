/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:45:36 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 10:55:20 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	nothing_in_a(t_env *env)
{
	t_elem	*tmp;

	tmp = env->b_start->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	env->b_start->next = NULL;
	env->a_start = env->b_start;
	env->b_start = tmp;
	return (SUCCESS);
}

int			do_pa(t_env *env)
{
	t_elem	*tmp;

	if (env == NULL)
		return (ERROR);
	if (env->b_size == 0)
		return (SUCCESS);
	env->a_size++;
	env->b_size--;
	tmp = env->b_start->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	if (env->a_start == NULL)
		return (nothing_in_a(env));
	env->b_start->next = env->a_start;
	env->a_start->prev = env->b_start;
	env->a_start = env->b_start;
	env->b_start = tmp;
	if (env->a_size == 1)
		env->a_end = env->a_start;
	return (SUCCESS);
}

static int	nothing_in_b(t_env *env)
{
	t_elem	*tmp;

	tmp = env->a_start->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	env->a_start->next = NULL;
	env->b_start = env->a_start;
	env->a_start = tmp;
	env->b_end = env->b_start;
	return (SUCCESS);
}

int			do_pb(t_env *env)
{
	t_elem	*tmp;

	if (env == NULL)
		return (ERROR);
	if (env->a_size == 0)
		return (SUCCESS);
	env->a_size--;
	env->b_size++;
	tmp = env->a_start->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	if (env->b_start == NULL)
		return (nothing_in_b(env));
	env->a_start->next = env->b_start;
	env->b_start->prev = env->a_start;
	env->b_start = env->a_start;
	env->a_start = tmp;
	if (env->a_size == 1)
		env->a_end = env->a_start;
	return (SUCCESS);
}
