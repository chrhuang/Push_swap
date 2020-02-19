/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:05:35 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 22:33:46 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static unsigned int	*find_front_back(t_env *env, unsigned int i)
{
	unsigned int	*fb;
	t_elem			*tmp;

	if ((fb = malloc(sizeof(int) * 2)) == NULL)
		return (NULL);
	fb[0] = 0;
	fb[1] = 1;
	tmp = env->a_start;
	while (tmp != NULL)
	{
		if (tmp->value >= env->chunk[i][0] && tmp->value <= env->chunk[i][1])
			break ;
		fb[0]++;
		tmp = tmp->next;
	}
	tmp = env->a_end;
	while (tmp != NULL)
	{
		if (tmp->value >= env->chunk[i][0] && tmp->value <= env->chunk[i][1])
			break ;
		fb[1]++;
		tmp = tmp->prev;
	}
	return (fb);
}

static int			rotate_push_to_a(t_env *env)
{
	char			rotate;

	rotate = search_rotate(env->b_start, env->b_end, env->b_max);
	while (env->b_max != env->b_start->value)
		rotate == 1 ? do_rb(env) : do_rrb(env);
	while (env->b_size > 0)
		do_pa(env);
	return (SUCCESS);
}

int					chunk_sort(t_env *env)
{
	t_elem			*tmp;
	unsigned int	i;
	unsigned int	*fb;
	char			rotate;

	if (chunk_init(env, &i) == ERROR)
		return (ERROR);
	while (env->a_size > 0)
	{
		tmp = env->a_start;
		if ((fb = find_front_back(env, i)) == NULL)
			return (ERROR);
		if (fb[0] == env->a_size && fb[1] == env->a_size + 1)
		{
			i++;
			rotate = search_rotate(env->b_start, env->b_end, env->b_max);
			free(fb);
			while (env->b_max != env->b_start->value)
				rotate == 1 ? do_rb(env) : do_rrb(env);
			continue;
		}
		r_list_a(env, fb[0] < fb[1] ? fb[0] : fb[1], fb[0] < fb[1] ? 1 : 0);
		free(fb);
	}
	return (rotate_push_to_a(env));
}
