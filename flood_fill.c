/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:13:40 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/18 03:55:26 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_x(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P' || tab[i][j] == 'C' || tab[i][j] == 'E')
			{
				write(1, "ERROR\nmap invalid\n", 17);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

int	x_p(char **tab)
{
	int	x;
	int	y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[x][y] == 'P')
				return (x);
			y++;
		}
		x++;
	}
	exit_w_message("ERROR\nP not foand!\n");
	return (0);
}

int	y_p(char **tab)
{
	int	x;
	int	y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[x][y] == 'P')
				return (y);
			y++;
		}
		x++;
	}
	exit_w_message("ERROR\nP not foand!\n");
	return (0);
}

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->height || y >= data->width)
		return ;
	if (data->tab[x][y] == 'E' || data->tab[x][y] == '0'
		|| data->tab[x][y] == 'C' || data->tab[x][y] == 'P')
	{
		data->tab[x][y] = 'x';
		flood_fill(data, x + 1, y);
		flood_fill(data, x - 1, y);
		flood_fill(data, x, y + 1);
		flood_fill(data, x, y - 1);
	}
}
