/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:07:01 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/12 13:42:30 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(int n, int neg)
{
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (neg == 0 ? ft_strdup("1") : ft_strdup("-1"));
}

static void	count(long *tmp, int *i, int n)
{
	*tmp = 1;
	*i = 0;
	while (*tmp <= n)
	{
		*tmp = *tmp * 10;
		*i = *i + 1;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		i;
	long	tmp;

	neg = n < 0 ? 1 : 0;
	n = n < 0 ? -n : n;
	if (n == -2147483648)
		return (ft_strjoin(ft_itoa(-21474), ft_itoa(83648)));
	if (n == 0 || n == 1)
		return (check(n, neg));
	count(&tmp, &i, n);
	if ((str = ft_strnew(i + neg)) == NULL)
		return (NULL);
	neg == 1 ? str[0] = '-' : 0;
	tmp = tmp / 10;
	while (tmp != 0)
	{
		str[neg] = n / (tmp) + '0';
		n = n % tmp;
		tmp = tmp / 10;
		neg = neg + 1;
	}
	str[neg] = '\0';
	return (str);
}
