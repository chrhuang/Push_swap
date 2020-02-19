/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:13:56 by chrhuang          #+#    #+#             */
/*   Updated: 2019/04/16 13:55:47 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_intlen(int nb)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	if (nb == 0)
		return (1);
	while (i <= nb)
	{
		i = i * 10;
		len = len + 1;
	}
	return (len);
}
