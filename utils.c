/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:47:36 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/18 03:49:03 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_w_message(char *message)
{
	write(2, RED, strlen(RED));
	write(2, message, strlen(message));
	write(2, NC, strlen(NC));
	exit(1);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->tab[i])
		free(data->tab[i++]);
	free(data->tab);
}

char	*ft_substr(char *src, int start, int end)
{
	int		i;
	char	*new_str;

	if (!src)
		return (NULL);
	i = 0;
	new_str = (char *)malloc((end - start) * sizeof(char) + 1);
	if (new_str == NULL)
		return (NULL);
	while (start < end)
	{
		new_str[i] = src[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlen_w_nl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!str && to_find)
		return (0);
	if (to_find[0] == '\0' || to_find == str)
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (str[i + j] == '\0' && to_find[j] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		if (to_find[j] == '\0' && str[i + j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
