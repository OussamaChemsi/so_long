/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:24:32 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/18 03:47:50 by ochemsi          ###   ########.fr       */
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
				exit_w_message("ERROR\nmap should be sorounded by walls!\n");
			j++;
		}
		i++;
	}
}

void	check_repeat(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] != '1') && (tab[i][j] != '0') && (tab[i][j] != 'x'))
				exit_w_message("ERROR\ninvalid map!\n");
			j++;
		}
		i++;
	}
}

void	check_path(char *av)
{
	char	*str;
	char	*to_find;

	to_find = ".ber";
	str = av;
	if (ft_strstr(str, to_find) == 0)
	{
		write(2, "ERROR\ninvalid path\n", 20);
		exit(1);
	}
}
