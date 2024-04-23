/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:37:38 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/23 13:38:39 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *archive, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!archive)
		return (ft_strdup(buff));
	if (!buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(archive) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (archive)
		while (archive[++i] != '\0')
			str[i] = archive[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(archive) + ft_strlen(buff)] = '\0';
	free(archive);
	return (str);
}

char	*ft_strdup(char *src)
{
	size_t	size;
	char	*dest;
	int		i;

	size = ft_strlen(src);
	dest = (char *)malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[size] = '\0';
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
