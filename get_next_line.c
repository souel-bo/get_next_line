/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:42:09 by souel-bo          #+#    #+#             */
/*   Updated: 2024/11/21 01:42:10 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*container;
	char		*temporary;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (container && !ft_strchr(container, '\n'))
	{
		line = ft_strdup_up(container, '\0');
		free(container);
		container = NULL;
	}
	else if (container && ft_strchr(container, '\n'))
	{
		temporary = ft_strdup_up(container, '\0');
		free(container);
		container = ft_strdup_up(ft_strchr(temporary, '\n') + 1, '\0');
		line = ft_strdup_up(temporary, '\n');
		free(temporary);
		return (line);
	}
	return (ft_read_line(line, &container, fd));
}

/*int main()
{
    int fd = open("test.txt", O_RDONLY);
    //char *test;
    //while ((test = get_next_line(fd)) != NULL)
    //{
        printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
      //  free(test);
	//}
   // printf("\n");
    close(fd);
    return 0; 
}*/