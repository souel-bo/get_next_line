/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:20:59 by souel-bo          #+#    #+#             */
/*   Updated: 2024/11/21 09:22:38 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_fill_line(char *line, char *buffer, char **container, int new_line)
{
	char	*temporary;

	if (!line && new_line == 1)
		line = ft_strdup_up(buffer, '\n');
	else if (!line && new_line == 0)
		line = ft_strdup_up(buffer, '\0');
	else if (line)
	{
		temporary = ft_strjoin_up(line, buffer);
		free(line);
		line = ft_strdup_up(temporary, '\0');
		free(temporary);
	}
	if (new_line == 1)
		*container = ft_strdup_up(ft_strchr(buffer, '\n') + 1, '\0');
	if (ft_strchr(line, '\n') && *ft_strchr(line, '\n') + 1 != '\0')
	{
		temporary = ft_strdup_up(line, '\n');
		free(line);
		line = ft_strdup_up(temporary, '\n');
		free(temporary);
	}
	free(buffer);
	return (line);
}

char	*ft_read_line(char *line, char **container, int fd)
{
	char	*buffer;
	ssize_t	readed;

	while (1)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
		if (!buffer)
			return (NULL);
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		else if (readed == 0)
		{
			free(buffer);
			return (line);
		}
		buffer[readed] = '\0';
		if (ft_strchr(buffer, '\n'))
			return (ft_fill_line(line, buffer, &*container, 1));
		line = ft_fill_line(line, buffer, &*container, 0);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*containers[OPEN_MAX];
	char		*temporary;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (containers[fd] && !ft_strchr(containers[fd], '\n'))
	{
		line = ft_strdup_up(containers[fd], '\0');
		free(containers[fd]);
		containers[fd] = NULL;
	}
	else if (containers[fd] && ft_strchr(containers[fd], '\n'))
	{
		temporary = ft_strdup_up(containers[fd], '\0');
		free(containers[fd]);
		containers[fd] = ft_strdup_up(ft_strchr(temporary, '\n') + 1, '\0');
		line = ft_strdup_up(temporary, '\n');
		free(temporary);
		return (line);
	}
	return (ft_read_line(line, &containers[fd], fd));
}
