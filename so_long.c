/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:06:37 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/22 03:14:37 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_map(t_data *data, int fd, char *tmp)
{
	while (data->line != NULL)
	{
		data->height++;
		if (data->line[(int)ft_strlen(data->line) - 1] == '\n')
		{
			tmp = ft_substr(data->line, 0, data->width);
			data->line = tmp;
		}
		if (data->width != (int)ft_strlen_w_nl(data->line))
			exit_w_message("ERROR\nyou have empty line!\n");
		data->lines = ft_strjoin(data->lines, data->line);
		free(data->line);
		data->line = get_next_line(fd);
	}

	close(fd);
}

void	reading_map(char *av, t_data *data)
{
	int		fd;
	char	*tmp;

	tmp = NULL;
	data->lines = NULL;
	data->height = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit_w_message("file not found!\n");
	data->line = get_next_line(fd);
	data->width = (int)ft_strlen_w_nl(data->line);
	if (data->line[(int)ft_strlen(data->line) - 1] == '\n')
	{
		tmp = ft_substr(data->line, 0, data->width);
		data->line = tmp;
	}
	if (!data->width)
		exit_w_message("ERROR\nempty map!\n");
	loop_map(data, fd, tmp);
}

void	tab_2d(t_data *data)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = data->width;
	data->tab = malloc(data->height * sizeof(char **) + 1);
	while (i < data->height)
	{
		data->tab[i] = ft_substr(data->lines, start, end);
		i++;
		start += data->width;
		end += data->width;
	}
	data->tab[i] = 0;
	check_pce(data);
	free(data->lines);
}

void	maistro_func(char *av, t_data *data)
{
	check_path(av);
	reading_map(av, data);
	tab_2d(data);
	flood_fill(data, x_p(data->tab), y_p(data->tab));
	check_repeat(data->tab);
	check_walls(data);
}

int	handler(int key, t_data *data)
{
	if (key == ESC)
	{
		// mlx_destroy_despaly(data->mlx);
		mlx_destroy_window(data->mlx, data->mlx_win);
		free_map(data);
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
	mlx_destroy_window(data->mlx, data->mlx_win);
	//free
	exit(0);
	return (0);
}

void	draw_map(t_data *data)
{
	
	int	i;
	int	j;

	i = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			if (data->tab[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
						j * 32, i * 32);
			if (data->tab[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
						data->collectibles, j * 32, i * 32);
			if (data->tab[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, j
						* 32, i * 32);
			if (data->tab[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit, j
						* 32, i * 32);
			j++;
		}
		i++;
	}
}
int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit_w_message("Takes two arguments\n");
	maistro_func(av[1], &data);
	// //
	// data.mlx = mlx_init();
	// data.mlx_win = mlx_new_window(data.mlx, data.width * 32, data.height * 32,
	// 		"so_long");
	// //
	// data.player = mlx_xpm_file_to_image(data.mlx, "textures/pac_open_right.xpm",
	// 		&data.width, &data.height);
	// data.collectibles = mlx_xpm_file_to_image(data.mlx,
	// 		"textures/pacdot_food.xpm", &data.width, &data.height);
	// data.exit = mlx_xpm_file_to_image(data.mlx, "textures/portal.xpm",
	// 		&data.width, &data.height);
	// data.wall = mlx_xpm_file_to_image(data.mlx, "textures/wall.xpm",
	// 		&data.width, &data.height);
	// if ((!data.player || !data.collectibles || !data.exit || !data.wall))
	// {
	// 	free_map(&data);
	// 	exit_w_message("ERROR\nimage  not foand!\n");
	// }
	// reading_map(av[1], &data);
	// tab_2d(&data);
	// draw_map(&data);
	// //
	// mlx_hook(data.mlx_win, 2, 1L << 0, handler, &data);
	// mlx_hook(data.mlx_win, 17, 1L << 1, close_window, &data);
	// mlx_loop(data.mlx);
	// free_map(&data);
	return (0);
}
