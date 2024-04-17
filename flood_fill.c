/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:13:40 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/16 18:32:17 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void flood_fill(char **tab, int x, int y)
{
    int height;
    int width;
    height = 0;

    while (tab[height])
        height++;
    width = ft_strlen(tab[1]);
    if (x < 0 || y < 0 || width < x || height < y)
        return;
    if (tab[y][x] == 'E' || tab[y][x] == '0' || tab[y][x] == 'C' || tab[y][x] == 'P')
    {
        tab[y][x] = 'x';

        flood_fill(tab, x + 1, y);
        flood_fill(tab, x - 1, y);
        flood_fill(tab, x, y + 1);
        flood_fill(tab, x, y - 1);
    }
}