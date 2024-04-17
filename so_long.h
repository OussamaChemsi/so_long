/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:45:50 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/18 00:47:59 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "includes/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	**tab;
	char	*tmp;
	char	*line;
	char	*lines;
	int		height;
	int		width;
	int		x_p;
	int		y_p;
	int		i;
	int		j;
	int		p;
	int		e;
	int		c;
	int		r;
}			t_data;

//
char		*ft_substr(char *src, int start, int end);
void		exit_w_message(char *message);
size_t		ft_strlen_w_nl(char *str);
void		free_map(t_data *data);
void		tab_2d(t_data *data);
void	check_path(char *av);

//

char		**ft_split(char *s, char c);
void		check_map(char **tab);
char		*ft_strstr(char *str, char *to_find);
void		check_pce(char **tab);
int			check_len(char **tab);
int			check_line_one(char **tab);
int			check_line_last(char **tab);
int			check_1_in_first(char **tab);
int			check_1_in_last(char **tab);
void		flood_fill(char ***tab, int x, int y);

int			y_p(char **tab);
int			x_p(char **tab);
void		check_x(char **tab);

#endif