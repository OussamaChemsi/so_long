/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:06:37 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/18 00:48:20 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_map(t_data *data, int fd, char *tmp)
{
	while (data->line != NULL)
	{
		data->height++;
		if (data->line[ft_strlen(data->line) - 1] == '\n')
		{
			tmp = ft_substr(data->line, 0, data->width);
			data->line = tmp;
		}
		if (data->width != ft_strlen_w_nl(data->line))
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

	data->lines = NULL;
	data->height = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit_w_message("file not found!\n");
	data->line = get_next_line(fd);
	data->width = (int)ft_strlen_w_nl(data->line);
	if (data->line[ft_strlen(data->line) - 1] == '\n')
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
	free(data->lines);
}

void	maistro_func(char *av, t_data *data)
{
	check_path(av);
	reading_map(av, data);
	tab_2d(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		exit_w_message("Takes two arguments\n");
	maistro_func(av[1], &data);
	free_map(&data);
	return (0);
}
