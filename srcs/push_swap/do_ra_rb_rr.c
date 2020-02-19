/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:22:18 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 11:19:40 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	do_ra(t_env *env)
{
	t_elem	*tmp;

	if (env == NULL)
		return (ERROR);
	if (env->a_size <= 2)
		return (do_sa(env));
	add_action(env, new_lst(RA));
	tmp = env->a_start->next;
	tmp->prev = NULL;
	env->a_end->next = env->a_start;
	env->a_start->prev = env->a_end;
	env->a_end = env->a_start;
	env->a_end->next = NULL;
	env->a_start = tmp;
	return (SUCCESS);
}

int	do_rb(t_env *env)
{
	t_elem	*tmp;

	if (env == NULL)
		return (ERROR);
	if (env->b_size <= 2)
		return (do_sb(env));
	add_action(env, new_lst(RB));
	tmp = env->b_start->next;
	tmp->prev = NULL;
	env->b_end->next = env->b_start;
	env->b_start->prev = env->b_end;
	env->b_end = env->b_start;
	env->b_end->next = NULL;
	env->b_start = tmp;
	return (SUCCESS);
}

int	do_rr(t_env *env)
{
	return (do_ra(env) == SUCCESS && do_rb(env) == SUCCESS ? SUCCESS : ERROR);
}
