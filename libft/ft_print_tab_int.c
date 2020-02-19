/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:42:47 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/13 16:03:17 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_tab_int(const int *tab, size_t size)
{
	size_t		i;

	if (tab == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		i = i + 1;
	}
	return (0);
}
