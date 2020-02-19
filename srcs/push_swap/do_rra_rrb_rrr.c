/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 22:42:43 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 11:20:56 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	do_rra(t_env *env)
{
	t_elem	*tmp;

	if (env == NULL)
		return (ERROR);
	if (env->a_size <= 2)
		return (do_sa(env));
	add_action(env, new_lst(RRA));
	tmp = env->a_end->prev;
	env->a_end->next = env->a_start;
	tmp->next = NULL;
	env->a_start->prev = env->a_end;
	env->a_end->prev = NULL;
	env->a_start = env->a_start->prev;
	env->a_end = tmp;
	return (SUCCESS);
}

int	do_rrb(t_env *env)
{
	t_elem	*tmp;

	if (env == NULL)
		return (ERROR);
	if (env->b_size <= 2)
		return (do_sb(env));
	add_action(env, new_lst(RRB));
	tmp = env->b_end->prev;
	env->b_end->next = env->b_start;
	env->b_start->prev = env->b_end;
	env->b_end->prev = NULL;
	env->b_start = env->b_end;
	env->b_end = tmp;
	env->b_end->next = NULL;
	return (SUCCESS);
}

int	do_rrr(t_env *env)
{
	return (do_rra(env) == SUCCESS && do_rrb(env) == SUCCESS ? SUCCESS : ERROR);
}
