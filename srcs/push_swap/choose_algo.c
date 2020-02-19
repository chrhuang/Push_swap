/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:10:41 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 22:57:13 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	choose_algo(t_env *env)
{
	if (env == NULL)
		return (ERROR);
	if (env->a_size <= 6)
		little_sort(env);
	else
		chunk_sort(env);
	return (SUCCESS);
}
