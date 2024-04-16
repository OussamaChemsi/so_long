/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:06:37 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/15 21:23:30 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_tab(char *av)
{
	int		fd;
	char	*line;
	char	*src;
	char	**tab;

	// line = NULL;
	// src = NULL;
	// tab = NULL;
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		write(1, "ERROR\nmap not found\n", 21);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	//111111111111111
	//width = ft_strlen(line);
	//height = 0 ;
	while (line != NULL)
	{
		//height++;
		src = ft_strjoin(src, line);
		free(line);
		line = get_next_line(fd);
		//if (ft_strlen(line) != width)
		//exit();
	}
	tab = ft_split(src, '\n');
	check_map(tab);
	check_pce(tab);
	close(fd);
}

int	main(int ac, char **av)
{
	char	*str;
	char	*to_find;

	if (ac == 2)
	{
		to_find = ".ber";
		str = av[1];
		if (ft_strstr(str, to_find) == 0)
		{
			write(1, "ERROR\ninvalid path\n", 20);
			exit(1);
		}
	}
	else
	{
		write(1, "takes 2 arguments\n", 19);
		exit(1);
	}
	map_tab(av[1]);
	return (0);
}
