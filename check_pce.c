/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:16:57 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/15 20:42:25 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_var *var)
{
	if (var->c <= 0 || var->p != 1 || var->e != 1 || var->r != 0)
	{
		write(1, "ERROR\n3ndk mochkil f P wla c wla e\n", 36);
		exit(EXIT_FAILURE);
	}
}

void	initialise_var(t_var **var)
{
	(*var)->c = 0;
	(*var)->p = 0;
	(*var)->e = 0;
	(*var)->i = 0;
	(*var)->j = 0;
	(*var)->r = 0;
}

void	check_pce(char **tab)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (!var)
		return ;
	initialise_var(&var);
	while (tab[var->i])
	{
		var->j = 0;
		while (tab[var->i][var->j])
		{
			if (tab[var->i][var->j] == 'P')
				var->p++;
			else if (tab[var->i][var->j] == 'C')
				var->c++;
			else if (tab[var->i][var->j] == 'E')
				var->e++;
			else if ((tab[var->i][var->j] != '1')
					&& (tab[var->i][var->j] != '0'))
				var->r++;
			var->j++;
		}
		var->i++;
	}
	print_error(var);
}

void	check_map(char **tab)
{
	if ((check_len(tab) == 0) || (check_line_one(tab) == 0)
		|| (check_line_last(tab) == 0) || (check_1_in_last(tab) == 0))
	{
		write(1, "ERROR\nmap invalid\n", 19);
		exit(EXIT_FAILURE);
	}
}
