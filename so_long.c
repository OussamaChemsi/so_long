/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:06:37 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/27 16:40:11 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_map(t_data *data, int fd)
{
	char	*line;

	while (data->line != NULL)
	{
		data->height++;
		if (data->width != (int)ft_strlen_w_nl(data->line))
		{
			free(data->lines);
			free(data->line);
			exit_w_message("ERROR\ninvalid map!\n");
		}
		if (data->line[(int)ft_strlen(data->line) - 1] == '\n')
		{
			line = data->line;
			data->line = ft_substr(data->line, 0, data->width, data);
			free(line);
		}
		data->lines = ft_strjoin(data->lines, data->line);
		free(data->line);
		data->line = get_next_line(fd);
	}
	free(data->line);
	close(fd);
}

void	reading_map(char *av, t_data *data)
{
	int		fd;
	char	*line;

	data->lines = NULL;
	data->height = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit_w_message("file not found!\n");
	data->line = get_next_line(fd);
	data->width = (int)ft_strlen_w_nl(data->line);
	if (!data->width)
	{
		free(data->line);
		free(data->lines);
		exit_w_message("ERROR\nempty map!\n");
	}
	if (data->line[(int)ft_strlen(data->line) - 1] == '\n')
	{
		line = data->line;
		data->line = ft_substr(data->line, 0, data->width, data);
		free(line);
	}
	loop_map(data, fd);
}

void	tab_2d(t_data *data)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = data->width;
	data->tab = malloc((data->height + 1) * sizeof(char *));
	if (!data->tab)
	{
		free(data->lines);
		exit_w_message("fail alocation");
	}
	while (i < data->height)
	{
		data->tab[i] = ft_substr(data->lines, start, end, data);
		i++;
		start += data->width;
		end += data->width;
	}
	data->tab[data->height] = NULL;
	free(data->lines);
	check_pce(data);
}

void	maistro_func(char *av, t_data *data)
{
	check_path(av);
	reading_map(av, data);
	tab_2d(data);
	flood_fill(data, x_p(data), y_p(data));
	check_repeat(data);
	check_walls(data);
	free_map(data);
	reading_map(av, data);
	tab_2d(data);
	flood_fill_2(data, x_p(data), y_p(data));
	check_x(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit_w_message("Takes two arguments\n");
	maistro_func(av[1], &data);
	data.mlx = mlx_init();
	initialize_mlx_vars(&data);
	message_xpm(&data);
	free_map(&data);
	reading_map(av[1], &data);
	tab_2d(&data);
	draw_map(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, handler, &data);
	mlx_hook(data.mlx_win, 17, 1L << 1, close_window_1, &data);
	mlx_loop(data.mlx);
	free_map(&data);
	return (0);
}
