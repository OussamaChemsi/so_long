/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:41:24 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/23 06:11:51 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dispaly_moves_exit(t_data *data)
{
	data->count_moves++;
	ft_printf("moves = %d", data->count_moves);
	free_map(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	exit(0);
}

void	move_right(t_data *data)
{
	int	j;

	data->i = -1;
	while (data->tab[++data->i])
	{
		j = -1;
		while (data->tab[data->i][++j])
		{
			if (data->tab[data->i][j] == 'P' && data->tab[data->i][j + 1] == 'E'
				&& data->c == 0)
				dispaly_moves_exit(data);
			if (data->tab[data->i][j] == 'P' && data->tab[data->i][j + 1] != 'E'
				&& data->tab[data->i][j + 1] != '1')
			{
				if (data->tab[data->i][j + 1] == 'C')
					data->c = data->c - 1;
				data->tab[data->i][j] = '0';
				data->tab[data->i][j + 1] = 'P';
				draw_map(data);
				data->count_moves++;
				ft_printf("%d\n", data->count_moves);
				return ;
			}
		}
	}
}

void	move_left(t_data *data)
{
	int	j;

	data->i = -1;
	while (data->tab[++data->i])
	{
		j = -1;
		while (data->tab[data->i][++j])
		{
			if (data->tab[data->i][j] == 'P' && data->tab[data->i][j - 1] == 'E'
				&& data->c == 0)
				dispaly_moves_exit(data);
			if (data->tab[data->i][j] == 'P' && data->tab[data->i][j - 1] != 'E'
				&& data->tab[data->i][j - 1] != '1')
			{
				if (data->tab[data->i][j - 1] == 'C')
					data->c = data->c - 1;
				data->tab[data->i][j] = '0';
				data->tab[data->i][j - 1] = 'P';
				draw_map(data);
				data->count_moves++;
				ft_printf("%d\n", data->count_moves);
				return ;
			}
		}
	}
}

void	move_down(t_data *data)
{
	int	j;

	data->i = -1;
	while (data->tab[++data->i])
	{
		j = -1;
		while (data->tab[data->i][++j])
		{
			if (data->tab[data->i][j] == 'P' && data->tab[data->i + 1][j] == 'E'
				&& data->c == 0)
				dispaly_moves_exit(data);
			if (data->tab[data->i][j] == 'P' && data->tab[data->i + 1][j] != 'E'
				&& data->tab[data->i + 1][j] != '1')
			{
				if (data->tab[data->i + 1][j] == 'C')
					data->c = data->c - 1;
				data->tab[data->i][j] = '0';
				data->tab[data->i + 1][j] = 'P';
				draw_map(data);
				data->count_moves++;
				ft_printf("%d\n", data->count_moves);
				return ;
			}
		}
	}
}

void	move_up(t_data *data)
{
	int	j;

	data->i = -1;
	while (data->tab[++data->i])
	{
		j = -1;
		while (data->tab[data->i][++j])
		{
			if (data->tab[data->i][j] == 'P' && data->tab[data->i - 1][j] == 'E'
				&& data->c == 0)
				dispaly_moves_exit(data);
			if (data->tab[data->i][j] == 'P' && data->tab[data->i - 1][j] != 'E'
				&& data->tab[data->i - 1][j] != '1')
			{
				if (data->tab[data->i - 1][j] == 'C')
					data->c = data->c - 1;
				data->tab[data->i][j] = '0';
				data->tab[data->i - 1][j] = 'P';
				draw_map(data);
				data->count_moves++;
				ft_printf("%d\n", data->count_moves);
				return ;
			}
		}
	}
}
