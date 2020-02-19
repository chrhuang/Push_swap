/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:01:37 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 22:29:43 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	find_min(t_env *env, t_elem *tmp, int max, unsigned int i)
{
	int	tmp_max;

	if (i == 0)
		return (env->a_min);
	tmp_max = max;
	max = env->a_max;
	while (tmp != NULL)
	{
		if (max > tmp->value && tmp->value > tmp_max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

/*
** chunk_size => formule de la fonction.
** apres plusieurs test, pour 100 nombres,
** le plus rapide pour le nombre de tronc
** est 5, et pour 500, c'est 11
** d'apres les tests, on trouve donc la formule
** y = (3 / 200) * x + 7 / 2.
*/

static int	fill_chunk(t_env *env, int *sorted)
{
	int	i;

	env->chunk_size = (3.0 / 200) * env->a_size + 3.5;
	if ((env->chunk = malloc(sizeof(int *) * env->chunk_size)) == NULL)
		return (ERROR);
	i = -1;
	while (++i < env->chunk_size)
		if ((env->chunk[i] = malloc(sizeof(int) * 2)) == NULL)
			return (ERROR);
	i = -1;
	while (++i < env->chunk_size)
	{
		env->chunk[i][0] = sorted[(int)(env->a_size *
		(1 / (float)env->chunk_size) * i)];
		if (i == env->chunk_size - 1)
			env->chunk[i][1] = env->a_max;
		else
			env->chunk[i][1] = sorted[(int)(env->a_size *
			(1 / (float)env->chunk_size) * (i + 1) - 1)];
	}
	return (SUCCESS);
}

int			chunk_init(t_env *env, unsigned int *ptr)
{
	int				*sorted;
	unsigned int	i;
	int				max;

	max = env->a_max;
	i = 0;
	*ptr = 0;
	sorted = NULL;
	if ((sorted = malloc(sizeof(int) * env->a_size)) == NULL)
		return (ERROR);
	while (i != env->a_size)
	{
		max = find_min(env, env->a_start, max, i);
		sorted[i] = max;
		i++;
	}
	if (fill_chunk(env, sorted) == ERROR)
		return (ERROR);
	free(sorted);
	return (SUCCESS);
}
