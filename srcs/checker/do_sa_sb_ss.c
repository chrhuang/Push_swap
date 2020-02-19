/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:27:34 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/18 22:05:45 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	do_sa(t_env *env)
{
	if (env == NULL)
		return (ERROR);
	if (env->a_size < 2)
		return (SUCCESS);
	ft_swap(&(env->a_start->value), &(env->a_start->next->value));
	return (SUCCESS);
}

int	do_sb(t_env *env)
{
	if (env == NULL)
		return (ERROR);
	if (env->b_size < 2)
		return (SUCCESS);
	ft_swap(&(env->b_start->value), &(env->b_start->next->value));
	return (SUCCESS);
}

int	do_ss(t_env *env)
{
	return (do_sa(env) == ERROR || do_sb(env) == ERROR ? ERROR : SUCCESS);
}
