/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:24:32 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/27 13:26:22 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			if (data->tab[0][j] != '1' || data->tab[i][0] != '1'
				|| data->tab[i][data->width - 1] != '1'
				|| data->tab[data->height - 1][j] != '1')
			{
				free_map(data);
				exit_w_message("ERROR\nmap should be sorounded by walls!\n");
			}
			j++;
		}
		i++;
	}
}

void	check_repeat(t_data *data)
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
				&& (data->tab[i][j] != 'x'))
			{
				free_map(data);
				exit_w_message("ERROR\ninvalid map!\n");
			}
			j++;
		}
		i++;
	}
}

void	check_path(char *av)
{
	char	*str;
	char	*to_find;
	size_t	len;

	to_find = ".ber";
	str = av;
	len = ft_strlen(str);
	if (len <= 4)
		exit_w_message("ERROR\ninvalid path\n");
	if ((ft_strstr(str, to_find) == 0) || (str[len - 5] == '/'))
		exit_w_message("ERROR\ninvalid path\n");
}

int	close_window_1(t_data *data)
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
	exit(1);
	return (1);
}
