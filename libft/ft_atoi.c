/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:38:23 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/19 11:01:34 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*check_my_str(const char *str)
{
	while (*str < '0' || *str > '9')
	{
		if (*str != '+' && *str != '-' && *str != '\0')
		{
			if (*str == '\n' || *str == '\f' || *str == '\r')
				str = str + 1;
			else if (*str == '\v' || *str == '\t' || *str == ' ')
				str = str + 1;
			else
				return (NULL);
		}
		else
			return (str);
	}
	return (str);
}

int					ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	neg;

	nb = 0;
	i = 0;
	if ((str = check_my_str(str)) == NULL)
		return (0);
	neg = str[0] == '-' ? 1 : 0;
	if (neg == 1 || *str == '+')
		str = str + 1;
	while (*str <= '9' && *str >= '0')
	{
		nb = nb * 10 + *str - '0';
		str = str + 1;
	}
	return (nb = (neg == 1 ? -nb : nb));
}
