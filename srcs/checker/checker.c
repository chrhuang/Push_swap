/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:55:39 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/24 10:38:07 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_elem	*new_elem(int value)
{
	t_elem	*new;

	if ((new = malloc(sizeof(t_elem))) == NULL)
		return (NULL);
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

static int		add_begin_elem(t_env *env, t_elem *new)
{
	if (new == NULL)
		return (ERROR);
	if (env->a_start == NULL)
	{
		env->a_start = new;
		env->a_size = env->a_size + 1;
		return (SUCCESS);
	}
	new->next = env->a_start;
	env->a_start->prev = new;
	env->a_start = new;
	env->a_size = env->a_size + 1;
	return (SUCCESS);
}

static int		init(t_env *env, int ac, char **av)
{
	t_elem	*tmp;

	env->a_start = NULL;
	env->b_start = NULL;
	env->a_size = 0;
	env->b_size = 0;
	while (ac > 0)
	{
		if (add_begin_elem(env, new_elem(ft_atoi(av[ac - 1]))) != SUCCESS)
			return (ERROR);
		ac--;
	}
	tmp = env->a_start;
	while (tmp->next != NULL)
		tmp = tmp->next;
	env->a_end = tmp;
	env->b_end = NULL;
	return (SUCCESS);
}

static int		have_error(t_env *env)
{
	ft_putstr_fd(ERROR_MSG, 2);
	free_env(env);
	return (ERROR);
}

int				main(int ac, char **av)
{
	t_env	env;

	if (ac == 1)
		return (ERROR);
	ac--;
	av++;
	if (check_arg(ac, av) == ERROR)
	{
		ft_putstr_fd(ERROR_MSG, 2);
		return (ERROR);
	}
	if (init(&env, ac, av) == ERROR)
		return (have_error(&env));
	if (checker(&env) == ERROR)
		return (have_error(&env));
	free_env(&env);
	return (SUCCESS);
}
