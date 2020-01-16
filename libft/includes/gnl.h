/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:10:03 by dcoloma           #+#    #+#             */
/*   Updated: 2020/01/14 17:10:11 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include "libft.h"

typedef struct	s_gnl
{
	char			*content;
	int				fd;
	struct s_gnl	*next;
}				t_gnl;
t_gnl			*ft_new_elem(char *content, int fd);
void			ft_add_elem(t_gnl **alst, t_gnl *new);
#endif
