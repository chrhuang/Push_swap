/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:06:02 by chrhuang          #+#    #+#             */
/*   Updated: 2019/01/22 11:35:56 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*search_file(t_list **list, int fd)
{
	t_list	*curr;

	curr = *list;
	while (curr != NULL)
	{
		if ((int)curr->content_size == fd)
			return (curr);
		curr = curr->next;
	}
	if ((curr = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	curr->content = ft_strdup("\0");
	curr->content_size = fd;
	curr->next = *list;
	*list = curr;
	return (curr);
}

static unsigned int	search_end(char *str)
{
	unsigned int	i;

	i = 0;
	while (str != NULL && str[i] != '\0' && str[i] != '\n')
		i = i + 1;
	return (i);
}

static int			check_line(t_list *curr, int len, char **line)
{
	unsigned int	end;
	char			*tmp;

	end = search_end(curr->content);
	if (len != BUFF_SIZE && ft_strlen(curr->content) == 0)
		return (0);
	if ((*line = ft_strdup(curr->content)) == NULL)
		return (-1);
	(*line)[end] = '\0';
	tmp = curr->content;
	if ((end == ft_strlen(curr->content) || end == ft_strlen(curr->content) - 1)
		&& len == 0)
		curr->content = ft_strdup("\0");
	else
		curr->content = ft_strdup(curr->content + end + 1);
	if (curr->content == NULL)
		return (-1);
	ft_memdel((void **)&tmp);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*curr;
	char			buff[BUFF_SIZE + 1];
	int				len;
	t_pos			pos;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) == -1)
		return (-1);
	curr = search_file(&list, fd);
	len = 0;
	if (ft_strchr(curr->content, '\n') != NULL)
		return (check_line(curr, len, line));
	pos.x = 1;
	pos.y = 0;
	while ((len = read(fd, buff, BUFF_SIZE)))
	{
		buff[len] = '\0';
		if ((curr->content = ft_strjoin_free(curr->content, buff, pos)) == NULL)
			return (-1);
		if (ft_strchr(curr->content, '\n') != NULL)
			break ;
	}
	return (check_line(curr, len, line));
}
