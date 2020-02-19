/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:53:37 by chrhuang          #+#    #+#             */
/*   Updated: 2018/11/19 11:02:46 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_tab(const char *str, char charset)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == charset)
		{
			nb = nb + 1;
			i = i + 1;
			while (str[i] == charset && str[i] != '\0')
				i = i + 1;
			i = i - 1;
		}
		i = i + 1;
	}
	return (nb + 1);
}

static int	len(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != charset)
		i = i + 1;
	return (i);
}

char		**ft_strsplit(const char *str, char charset)
{
	int		i;
	int		j;
	int		check;
	char	**tab;

	j = 0;
	if (str == NULL || (tab = ft_tabnew(len_tab(str, charset) + 1)) == NULL)
		return (NULL);
	while (*str != '\0')
	{
		check = 0;
		i = 0;
		while (*str == charset && *str != '\0')
			str = str + 1;
		if ((tab[j] = malloc(sizeof(char) * (len(str, charset) + 1))) == NULL)
			return (NULL);
		while (*str != charset && *str != '\0')
		{
			check = 1;
			tab[j][i++] = *str++;
		}
		check == 1 ? tab[j++][i] = '\0' : 0;
	}
	tab[j] = 0;
	return (tab);
}
