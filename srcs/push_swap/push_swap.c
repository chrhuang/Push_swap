/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:57:00 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/24 10:10:56 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	add_begin_elem(t_env *env, t_elem *new)
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

static void	init_env_var(t_env *env)
{
	env->a_start = NULL;
	env->b_start = NULL;
	env->a_size = 0;
	env->b_size = 0;
	env->b_min = 0;
	env->b_max = 0;
	env->b_end = NULL;
	env->action_start = NULL;
	env->action_end = NULL;
	env->chunk = NULL;
	env->chunk_size = 0;
}

static int	init(t_env *env, int ac, char **av)
{
	t_elem	*tmp;

	init_env_var(env);
	while (ac > 0)
	{
		if (add_begin_elem(env, new_lst(ft_atoi(av[ac - 1]))) != SUCCESS)
			return (ERROR);
		ac--;
	}
	tmp = env->a_start;
	env->a_min = tmp->value;
	env->a_max = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			env->a_end = tmp;
		env->a_max < tmp->value ? env->a_max = tmp->value : 0;
		env->a_min > tmp->value ? env->a_min = tmp->value : 0;
		tmp = tmp->next;
	}
	return (SUCCESS);
}

static int	have_error(t_env *env)
{
	if (env != NULL)
		free_env(env);
	ft_putstr_fd(ERROR_MSG, 2);
	return (ERROR);
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac == 1)
		return (have_error(NULL));
	ac--;
	av++;
	if (check_arg(ac, av) == ERROR)
	{
		ft_putstr_fd(ERROR_MSG, 2);
		return (ERROR);
	}
	if (init(&env, ac, av) == ERROR)
		return (have_error(&env));
	if (is_sorted(&env) == SUCCESS)
	{
		free_env(&env);
		return (SUCCESS);
	}
	if (choose_algo(&env) == ERROR)
		return (have_error(&env));
	opti_action(&env);
	print_action(&env);
	free_env(&env);
	return (SUCCESS);
}
