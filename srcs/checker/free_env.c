/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 21:20:35 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/18 21:41:00 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
	env->b_start = NULL;
	env->a_end = NULL;
	env->b_end = NULL;
}
