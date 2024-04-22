/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:41:24 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/22 02:16:08 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *data)
{
    mlx_clear_window(data->mlx , data->mlx_win);
	int	i;
	int	j;
    i = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			if (data->tab[i][j] == 'P' && data->tab[i][j + 1] == 'E')
			{
				data->count_moves++;
				printf("moves = %d", data->count_moves);
				free_map(data);
				mlx_destroy_window(data->mlx, data->mlx_win);
				exit(0);
			}
			if (data->tab[i][j] == 'P' && data->tab[i][j + 1] != 'E'
				&& data->tab[i][j + 1] != '1')
			{
				data->tab[i][j] = '0';
				data->tab[i][j + 1] = 'P';
				draw_map(data);
				data->count_moves++;
				printf("%d", data->count_moves);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_left(t_data *data)
{
    (void)data;
}

void	move_down(t_data *data)
{
  (void)data;
}

void	move_up(t_data *data)
{
    (void)data;
}