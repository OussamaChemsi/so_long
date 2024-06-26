/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:13:40 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/24 05:46:27 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_x(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			if ((data->tab[i][j] != '1') && (data->tab[i][j] != '0')
				&& (data->tab[i][j] != '2') && (data->tab[i][j] != 'E'))
			{
				free_map(data);
				exit_w_message("ERROR\nmap invalid\n");
			}
			j++;
		}
		i++;
	}
}

int	x_p(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->tab[x])
	{
		y = 0;
		while (data->tab[x][y])
		{
			if (data->tab[x][y] == 'P')
				return (x);
			y++;
		}
		x++;
	}
	free_map(data);
	exit_w_message("ERROR\nP not foand!\n");
	return (0);
}

int	y_p(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->tab[x])
	{
		y = 0;
		while (data->tab[x][y])
		{
			if (data->tab[x][y] == 'P')
				return (y);
			y++;
		}
		x++;
	}
	free_map(data);
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

void	flood_fill_2(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->height || y >= data->width)
		return ;
	if (data->tab[x][y] == '0' || data->tab[x][y] == 'C'
		|| data->tab[x][y] == 'P')
	{
		data->tab[x][y] = '2';
		flood_fill_2(data, x + 1, y);
		flood_fill_2(data, x - 1, y);
		flood_fill_2(data, x, y + 1);
		flood_fill_2(data, x, y - 1);
	}
}
