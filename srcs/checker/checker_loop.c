/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 21:57:36 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/24 10:36:06 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	init_command(char ***tab, int (**tab_ptr)(t_env *env))
{
	if ((*tab = malloc(sizeof(char *) * 11)) == NULL)
		return (ERROR);
	(*tab)[0] = "sa";
	(*tab)[1] = "sb";
	(*tab)[2] = "ss";
	(*tab)[3] = "pa";
	(*tab)[4] = "pb";
	(*tab)[5] = "ra";
	(*tab)[6] = "rb";
	(*tab)[7] = "rr";
	(*tab)[8] = "rra";
	(*tab)[9] = "rrb";
	(*tab)[10] = "rrr";
	tab_ptr[0] = do_sa;
	tab_ptr[1] = do_sb;
	tab_ptr[2] = do_ss;
	tab_ptr[3] = do_pa;
	tab_ptr[4] = do_pb;
	tab_ptr[5] = do_ra;
	tab_ptr[6] = do_rb;
	tab_ptr[7] = do_rr;
	tab_ptr[8] = do_rra;
	tab_ptr[9] = do_rrb;
	tab_ptr[10] = do_rrr;
	return (SUCCESS);
}

static int	command_not_found(char *str, int (**t_ptr)(t_env *env), char **tab)
{
	free(str);
	free(t_ptr);
	free(tab);
	return (ERROR);
}

int			checker(t_env *env)
{
	int		(**tab_ptr)(t_env *env);
	char	*str;
	char	**tab;
	int		i;

	if ((tab_ptr = malloc(sizeof(tab_ptr) * 11)) == NULL)
		return (ERROR);
	if (init_command(&tab, tab_ptr) == ERROR)
		return (ERROR);
	while (get_next_line(0, &str) == 1)
	{
		i = -1;
		while (++i < 11)
			if (ft_strcmp(tab[i], str) == 0)
			{
				tab_ptr[i](env);
				break ;
			}
		if (i == 11)
			return (command_not_found(str, tab_ptr, tab));
		free(str);
	}
	free(tab_ptr);
	free(tab);
	return (is_sorted(env));
}
