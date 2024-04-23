/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:16:57 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/22 22:19:35 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_data *data)
{
	if (data->c <= 0 || data->p != 1 || data->e != 1 || data->r != 0)
	{
		free_map(data);
		exit_w_message("ERROR\n the map should have P,E and C\n");
	}
}

void	check_pce(t_data *data)
{
	data->i = 0;
	data->c = 0;
	data->p = 0;
	data->e = 0;
	data->r = 0;
	while (data->tab[data->i])
	{
		data->j = 0;
		while (data->tab[data->i][data->j])
		{
			if (data->tab[data->i][data->j] == 'P')
				data->p++;
			else if (data->tab[data->i][data->j] == 'E')
				data->e++;
			else if (data->tab[data->i][data->j] == 'C')
				data->c++;
			else if ((data->tab[data->i][data->j] != '1')
					&& (data->tab[data->i][data->j] != '0'))
				data->r++;
			data->j++;
		}
		data->i++;
	}
	print_error(data);
}
