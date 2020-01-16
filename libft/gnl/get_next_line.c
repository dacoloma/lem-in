/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:14:30 by dcoloma           #+#    #+#             */
/*   Updated: 2019/03/22 12:06:26 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*ft_get_elem(t_gnl **head, const int fd)
{
	t_gnl	*elem;

	elem = *head;
	while (elem && elem->fd != fd)
		elem = elem->next;
	if (elem == NULL)
	{
		elem = ft_new_elem(NULL, fd);
		ft_add_elem(head, elem);
	}
	return (elem);
}

static int		ft_is_valid(const int fd, char **line)
{
	char	*buf[1];

	return (!((fd < 0 || line == NULL || (read(fd, buf, 0) < 0)
					|| BUFF_SIZE < 1)));
}

static void		ft_get_line(char *tmp, char **line, t_gnl *elem)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	*line = ft_strsub(tmp, 0, i);
	elem->content = (tmp[i] == '\n') ? ft_strdup(tmp + i + 1) : NULL;
	free(tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*head = NULL;
	t_gnl			*elem;
	char			*tmp;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if (!ft_is_valid(fd, line))
		return (-1);
	elem = ft_get_elem(&head, fd);
	tmp = elem->content;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = (*tmp == '\0') ? ft_strdup(buf) : ft_strjoin(elem->content, buf);
		free(elem->content);
		elem->content = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if ((ret == 0 && !elem->content) || *tmp == '\0')
		return (0);
	ft_get_line(tmp, line, elem);
	return (1);
}
