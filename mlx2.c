/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:46:32 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/27 16:48:35 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handler(int key, t_data *data)
{
	if (key == ESC)
	{
		close_window(data);
		exit(0);
	}
	if (key == W)
		move_up(data);
	if (key == A)
		move_left(data);
	if (key == S)
		move_down(data);
	if (key == D)
		move_right(data);
	return (1);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->collectibles);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->noting);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data);
	return (1);
}

void	draw_map(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	data->i = -1;
	while (data->tab[++data->i])
	{
		data->j = -1;
		while (data->tab[data->i][++data->j])
		{
			if (data->tab[data->i][data->j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
					data->j * 32, data->i * 32);
			if (data->tab[data->i][data->j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->noting,
					data->j * 32, data->i * 32);
			if (data->tab[data->i][data->j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->collectibles, data->j * 32, data->i * 32);
			if (data->tab[data->i][data->j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall,
					data->j * 32, data->i * 32);
			if (data->tab[data->i][data->j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit,
					data->j * 32, data->i * 32);
		}
	}
}
