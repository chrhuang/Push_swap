/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:45:00 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 22:54:00 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR_MSG	"Error\n"
# define OK_MSG		"OK\n"
# define KO_MSG		"KO\n"

enum {SA, SB, PA, PB, RA, RB, RRA, RRB, SS, RR, RRR};

typedef struct		s_elem
{
	int				value;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_env
{
	t_elem			*a_start;
	t_elem			*b_start;
	t_elem			*a_end;
	t_elem			*b_end;
	unsigned int	a_size;
	unsigned int	b_size;
	int				a_min;
	int				a_max;
	int				b_min;
	int				b_max;
	int				**chunk;
	int				chunk_size;
	t_elem			*action_start;
	t_elem			*action_end;
	unsigned int	action_size;
}					t_env;

void				free_env(t_env *env);
int					check_arg(int ac, char **av);
int					checker(t_env *env);
int					do_sa(t_env *env);
int					do_sb(t_env *env);
int					do_ss(t_env *env);
int					do_pa(t_env *env);
int					do_pb(t_env *env);
int					do_ra(t_env *env);
int					do_rb(t_env *env);
int					do_rr(t_env *env);
int					do_rra(t_env *env);
int					do_rrb(t_env *env);
int					do_rrr(t_env *env);
t_elem				*new_lst(int value);
int					search_min_max(t_env *env);
int					is_sorted(t_env *env);
int					choose_algo(t_env *env);
int					little_sort(t_env *env);
int					chunk_sort(t_env *env);
int					add_action(t_env *env, t_elem *new);
int					opti_action(t_env *env);
int					print_action(t_env *env);
char				search_rotate(t_elem *start, t_elem *end, int value);
int					chunk_init(t_env *env, unsigned int *ptr);
void				r_list_a(t_env *env, int pos, char direction);

#endif
