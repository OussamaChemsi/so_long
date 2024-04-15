/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:57:44 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/14 16:37:49 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (!s)
		return (0);
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**free_tab(char **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**allocate_memory(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	return (tab);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	tab = allocate_memory(s, c);
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < ft_countword(s, c))
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] != c && s[i])
			i++;
		tab[j] = ft_substr(s, k, i - k);
		if (i > k && !(tab[j]))
			return (free_tab(tab, j));
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
