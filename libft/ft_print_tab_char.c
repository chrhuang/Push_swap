/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:39:31 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/13 15:49:33 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_tab_char(const char **tab)
{
	if (tab == NULL)
		return (-1);
	while (*tab != NULL)
	{
		ft_putstr(*tab);
		ft_putchar('\n');
		tab = tab + 1;
	}
	return (0);
}
