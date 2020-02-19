/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 21:08:37 by chrhuang          #+#    #+#             */
/*   Updated: 2019/06/19 13:05:18 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_isinteger(char *s)
{
	unsigned int	nb;

	if (!s || !ft_isnumber(s))
		return (0);
	nb = 0;
	while (ft_isspace(*s))
		++s;
	(*s == '-' || *s == '+') ? ++s : 0;
	while (ft_isdigit(*s) && nb < INT_MAX)
		nb = (nb * 10) + *s++ - '0';
	return (nb <= INT_MAX);
}
