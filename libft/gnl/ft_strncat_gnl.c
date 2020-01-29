/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:48:49 by dcoloma           #+#    #+#             */
/*   Updated: 2020/01/21 17:48:51 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat_gnl(char *s1, const char *s2, int len)
{
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	while (j < len)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
