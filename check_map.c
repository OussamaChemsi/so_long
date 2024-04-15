/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:24:32 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/15 01:57:43 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check len deyalhom wache fhalfhal
int	check_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[0]) == ft_strlen(tab[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
// ster lwl  fihom kghir 1

int	check_line_one(char **tab)
{
	int	j;

	j = 0;
	while (tab[0][j])
	{
		if (tab[0][j] == '1')
			j++;
		else
			return (0);
	}
	return (1);
}

// ster lakher o lakher fihom kghir 1
int	check_line_last(char **tab)
{
	int	a;
	int	j;

	a = 0;
	j = 0;
	while (tab[a])
		a++;
	while (tab[a - 1][j])
	{
		if (tab[a - 1][j] == '1')
			j++;
		else
			return (0);
	}
	return (1);
}
// setora li lwsst fihom 1 flwl

int	check_1_in_first(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}
// setora li lwsst fihom 1 f lkher

int	check_1_in_last(char **tab)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 0;
	b = ft_strlen(tab[1]) - 1;
	while (tab[a])
		a++;
	while (tab[i] && i <= a - 1)
	{
		if (tab[i][b] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}
