/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:04:03 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/27 16:47:00 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_supor(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data);
	exit_w_message("Error, Invalid xpm");
}

void	message_xpm2(t_data *data)
{
	if (!data->exit)
	{
		mlx_destroy_image(data->mlx, data->player);
		mlx_destroy_image(data->mlx, data->collectibles);
		mlx_destroy_image(data->mlx, data->wall);
		mlx_destroy_image(data->mlx, data->noting);
		xpm_supor(data);
	}
	if (!data->collectibles)
	{
		mlx_destroy_image(data->mlx, data->player);
		mlx_destroy_image(data->mlx, data->wall);
		mlx_destroy_image(data->mlx, data->noting);
		mlx_destroy_image(data->mlx, data->exit);
		xpm_supor(data);
	}
	if (!data->noting)
	{
		mlx_destroy_image(data->mlx, data->player);
		mlx_destroy_image(data->mlx, data->collectibles);
		mlx_destroy_image(data->mlx, data->wall);
		mlx_destroy_image(data->mlx, data->exit);
		xpm_supor(data);
	}
}

void	message_xpm(t_data *data)
{
	message_xpm2(data);
	if (!data->player)
	{
		mlx_destroy_image(data->mlx, data->collectibles);
		mlx_destroy_image(data->mlx, data->wall);
		mlx_destroy_image(data->mlx, data->noting);
		mlx_destroy_image(data->mlx, data->exit);
		xpm_supor(data);
	}
	if (!data->wall)
	{
		mlx_destroy_image(data->mlx, data->player);
		mlx_destroy_image(data->mlx, data->collectibles);
		mlx_destroy_image(data->mlx, data->noting);
		mlx_destroy_image(data->mlx, data->exit);
		xpm_supor(data);
	}
}

void	initialize_mlx_vars(t_data *data)
{
	data->count_moves = 0;
	data->mlx_win = mlx_new_window(data->mlx, data->width * 32,
			data->height * 32, "so_long");
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
