/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:13:40 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/17 04:43:00 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int check_x(char **tab)
{
    int i;
    int j;

    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (tab[i][j] == 'P' || tab[i][j] == 'C' || tab[i][j] == 'E')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
int x_p(char **tab)
{
    int i;
    int j;

    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (tab[i][j] == 'P')
                return (j);
            j++;
        }
        i++;
    }
    return (0);
}
int y_p(char **tab)
{
    int i;
    int j;

    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (tab[i][j] == 'P')
                return (i);
            j++;
        }
        i++;
    }
    return (0);
}
void flood_fill(char **tab, int x, int y)
{
    int height;
    int width;

    height = 0;
    while (tab[height])
        height++;
    width = ft_strlen(tab[1]);
    if (x < 0 || y < 0 || x <= height ||  y <= width)
    {
        write(1, "ERROR\nmap incorrect\n", 21);
        exit(EXIT_FAILURE);
    }
    printf("whidth %d\n", width);
    printf("hieght %d\n", height);
    if (tab[x][y] == 'E' || tab[x][y] == '0' || tab[x][y] == 'C' || tab[x][y] == 'P')
    {
        tab[x][y] = 'x';

        flood_fill(tab, x + 1, y);
        flood_fill(tab, x - 1, y);
        flood_fill(tab, x, y + 1);
        flood_fill(tab, x, y - 1);
    }
    int a = 0;
    while (tab[a])
    {
        write(1, tab[a], ft_strlen(tab[a]));
        write(1, "\n", 1);
        a++;
    }
}