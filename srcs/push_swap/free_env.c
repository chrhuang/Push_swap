/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:05:22 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 21:58:03 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	free_action(t_env *env)
{
	t_elem	*tmp;

	while (env->action_start != NULL)
	{
		tmp = env->action_start;
		env->action_start = env->action_start->next;
		if (tmp != NULL)
			free(tmp);
	}
	env->action_end = NULL;
}

static void	free_chunk(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->chunk_size)
		free(env->chunk[i]);
	free(env->chunk);
}

void		free_env(t_env *env)
{
	t_elem	*tmp;

	while (env->a_start != NULL)
	{
		tmp = env->a_start;
		env->a_start = env->a_start->next;
		if (tmp != NULL)
			free(tmp);
	}
	while (env->b_start != NULL)
	{
		tmp = env->b_start;
		env->b_start = env->b_start->next;
		if (tmp != NULL)
			free(tmp);
	}
	env->a_end = NULL;
	env->b_end = NULL;
	free_action(env);
	free_chunk(env);
}
