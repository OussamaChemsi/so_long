/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:45:50 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/22 03:05:13 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "includes/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*collectibles;
	void	*walls;
	void	*exit;
	void	*wall;
	char	**tab;
	char	*tmp;
	char	*line;
	char	*lines;
	int		count_moves;
	int		height;
	int		width;
	int		i;
	int		j;
	int		p;
	int		e;
	int		c;
	int		r;
}			t_data;
# define RED "\033[0;31m"
# define NC "\033[0;0m"
# define W 119
# define D 100
# define S 115
# define A 97
# define ESC 65307

char		*ft_substr(char *src, int start, int end);
void		exit_w_message(char *message);
size_t		ft_strlen_w_nl(char *str);
void		free_map(t_data *data);
void		tab_2d(t_data *data);
void		check_path(char *av);
void		flood_fill(t_data *data, int x, int y);
int			y_p(char **tab);
int			x_p(char **tab);
void		check_pce(t_data *data);
void		check_repeat(char **tab);
char		*ft_strstr(char *str, char *to_find);
void		check_x(char **tab);
void		check_walls(t_data *data);
void		move_up(t_data *data);
void		move_left(t_data *data);
void		move_down(t_data *data);
void		move_right(t_data *data);
void	draw_map(t_data *data);

// int			ft_putnbr(int n);

#endif