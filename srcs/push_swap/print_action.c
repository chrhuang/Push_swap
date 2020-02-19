/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:45:19 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 20:47:24 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	fill_action_tab(char **str)
{
	str[0] = "sa\n";
	str[1] = "sb\n";
	str[2] = "pa\n";
	str[3] = "pb\n";
	str[4] = "ra\n";
	str[5] = "rb\n";
	str[6] = "rra\n";
	str[7] = "rrb\n";
	str[8] = "ss\n";
	str[9] = "rr\n";
	str[10] = "rrr\n";
}

int			print_action(t_env *env)
{
	t_elem	*tmp;
	char	**str;

	if (env == NULL)
		return (ERROR);
	tmp = env->action_start;
	if ((str = malloc(sizeof(char *) * 11)) == NULL)
		return (ERROR);
	fill_action_tab(str);
	while (tmp != NULL)
	{
		ft_putstr(str[tmp->value]);
		tmp = tmp->next;
	}
	free(str);
	return (SUCCESS);
}
