/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:25:30 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/14 10:30:01 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(const char *base)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	if (base[0] == '\0')
		return (-1);
	while (base[i] != '\0')
	{
		j = i + 1;
		tmp = base[i];
		while (base[j] != '\0')
		{
			if (tmp == base[j] || tmp == '+' || tmp == '-')
				return (-1);
			j = j + 1;
		}
		i = i + 1;
	}
	i = 0;
	while (base[i] != '\0')
		i = i + 1;
	return (i);
}

static void	check_neg(int *nbr)
{
	if (*nbr < 0)
	{
		ft_putchar('-');
		*nbr = -(*nbr);
	}
}

void		ft_putnbr_base(int nbr, const char *base)
{
	int	len;

	if (base == NULL)
		return ;
	if ((len = check_base(base)) == -1)
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(-21474, base);
		ft_putnbr_base(83648, base);
		return ;
	}
	check_neg(&nbr);
	if (nbr >= len)
	{
		ft_putnbr_base(nbr / len, base);
		ft_putchar(base[nbr % len]);
	}
	else
		ft_putchar(base[nbr % len]);
}
