/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 22:30:54 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 22:41:26 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static unsigned int	find_max_up(t_env *env, int max)
{
	t_elem			*tmp;
	unsigned int	nb;

	tmp = env->b_start;
	nb = 0;
	while (tmp != NULL && tmp->value != max)
	{
		nb++;
		tmp = tmp->next;
	}
	return (nb);
}

static unsigned int	find_max_down(t_env *env, int max)
{
	t_elem			*tmp;
	unsigned int	nb;

	tmp = env->b_end;
	nb = 1;
	while (tmp != NULL && tmp->value != max)
	{
		nb++;
		tmp = tmp->prev;
	}
	return (nb);
}

static unsigned int	*find_max(t_env *env, int value)
{
	t_elem			*tmp;
	unsigned int	*fb;
	int				max;

	if ((fb = malloc(sizeof(int) * 2)) == NULL)
		return (NULL);
	max = env->b_min;
	tmp = env->b_start;
	while (tmp != NULL)
	{
		if (max < tmp->value && tmp->value < value)
			max = tmp->value;
		tmp = tmp->next;
	}
	fb[0] = find_max_up(env, max);
	fb[1] = find_max_down(env, max);
	while (tmp != NULL && tmp->value != max)
	{
		fb[1]++;
		tmp = tmp->prev;
	}
	max = fb[0] < fb[1] ? 1 : -1;
	fb[0] = max == 1 ? fb[0] : fb[1];
	fb[1] = max;
	return (fb);
}

static void			r_list_b(t_env *env, int value)
{
	unsigned int	*fb;
	t_elem			*tmp;
	char			rotate;

	tmp = env->b_start;
	fb = NULL;
	if (tmp == NULL)
		return ;
	if (value > env->b_max || value < env->b_min)
	{
		rotate = search_rotate(env->b_start, env->b_end, env->b_max);
		while (env->b_max != env->b_start->value)
			rotate == 1 ? do_rb(env) : do_rrb(env);
	}
	else
	{
		fb = find_max(env, value);
		while (fb[0] > 0)
		{
			fb[1] == 1 ? do_rb(env) : do_rrb(env);
			fb[0]--;
		}
	}
	free(fb);
}

void				r_list_a(t_env *env, int pos, char direction)
{
	int	check;
	int	value;

	check = env->a_max;
	while (pos--)
		direction == 1 ? do_ra(env) : do_rra(env);
	value = env->a_start->value;
	r_list_b(env, value);
	do_pb(env);
}
