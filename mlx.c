/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:04:03 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/23 13:42:07 by ochemsi          ###   ########.fr       */
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

void	message_xpm(t_data *data)
{
	if (!data->player || !data->wall || !data->exit || !data->collectibles)
	{
		close_window(data);
		exit_w_message("Error, Invalid xpm");
	}
}

void	initialize_mlx_vars(t_data *data)
{
	data->count_moves = 0;
	data->mlx_win = mlx_new_window(data->mlx, data->width * 32, data->height
			* 32, "so_long");
	data->player = mlx_xpm_file_to_image(data->mlx,
			"textures/pac_open_right.xpm",
			&data->width,
			&data->height);
	data->collectibles = mlx_xpm_file_to_image(data->mlx,
			"textures/pacdot_food.xpm",
			&data->width,
			&data->height);
	data->exit = mlx_xpm_file_to_image(data->mlx, "textures/portal.xpm",
			&data->width, &data->height);
	data->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
			&data->width, &data->height);
	data->noting = mlx_xpm_file_to_image(data->mlx, "textures/noting.xpm",
			&data->width, &data->height);
}
