/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:27:55 by chrhuang          #+#    #+#             */
/*   Updated: 2019/01/29 14:28:12 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_ptr(char *s, int *nbr)
{
	int nb;
	int i;
	int sign;

	nb = 0;
	sign = (s[0] == '-' && s[1]) ? 1 : 0;
	i = sign;
	while (i >= 0 && s[i])
	{
		if (nb == 214748364 && ((sign && s[i] > '8') || (!sign && s[i] > '7')))
			return (FAIL);
		else if (s[i] < '0' || s[i] > '9' || nb > 214748364)
			return (FAIL);
		else
		{
			nb = nb * 10 + s[i] - 48;
			i++;
		}
	}
	if (sign != 0)
		nb = -nb;
	*nbr = nb;
	return (SUCCESS);
}
