/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:47:36 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/18 00:40:54 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "so_long.h"

void exit_w_message(char *message)
{
    write(2, message, ft_strlen(message));
    exit(1);
}

void free_map(t_data *data)
{
    int i;

    i = 0;
    while (data->tab[i])
        free(data->tab[i++]);
    free(data->tab);
}

char *ft_substr(char *src, int start, int end)
{
    int i;
    char *new_str;
    
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

size_t ft_strlen_w_nl(char *str)
{
    size_t i;
    
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
