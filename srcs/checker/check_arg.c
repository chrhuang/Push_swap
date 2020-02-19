/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 21:00:07 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/18 22:30:49 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
			if (!ft_strcmp(av[i], av[j]))
				return (ERROR);
	}
	i = -1;
	while (++i < ac)
		if (!ft_isnumber(av[i]))
			return (ERROR);
		else if (!ft_isinteger(av[i]))
			return (ERROR);
	return (SUCCESS);
}
