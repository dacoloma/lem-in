/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoloma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:24:43 by dcoloma           #+#    #+#             */
/*   Updated: 2018/11/15 13:57:59 by dcoloma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_char_count(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		wd_index;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_word_count(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	wd_index = 0;
	while (s[i] && wd_index < len)
	{
		while (s[i] == c)
			i++;
		if ((tab[wd_index] = ft_strsub(s, i, ft_char_count(s, c, i))) == NULL)
			return (NULL);
		while (s[i] && s[i] != c)
			i++;
		wd_index++;
	}
	tab[wd_index] = 0;
	return (tab);
}
