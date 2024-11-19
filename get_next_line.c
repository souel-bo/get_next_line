/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:20:19 by souel-bo          #+#    #+#             */
/*   Updated: 2024/11/19 20:45:26 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_new_line(char *container)
{
	int	i;

	if (!container)
		return (0);
	i = 0;
	while (container[i])
	{
		if (container[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_remain_line(char *container)
{
	char	*new_str;
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (container == NULL)
		return (NULL);
	while (container[i] != '\n' && container[i] != '\0')
		i++;
	if (container[i] == '\0')
		return (free(container), NULL);
	new_str = malloc(ft_strlen(container) - i);
	if (!new_str)
		return (free(container), NULL);
	if (container[i] == '\n')
		i++;
	while (container[i + x])
	{
		new_str[x] = container[i + x];
		x++;
	}
	new_str[x] = '\0';
	return (free(container), new_str);
}

char	*ft_extract_line(char *container)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (container[0] == '\0')
		return (NULL);
	while (container[i] != '\0' && container[i] != '\n')
		i++;
	if (container[i] == '\n')
	{
		line = malloc(i + 2);
		if (!line)
			return (NULL);
		line[i + 1] = '\0';
		while (j <= i)
		{
			line[j] = container[j];
			j++;
		}
	}
	else
		line = ft_strdup(container);
	return (line);
}

char	*ft_read_line(char *container, int fd)
{
	ssize_t	readed;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_check_new_line(container) == 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
		{
			if (readed == 0)
				return (free(buffer), container);
			return (free(buffer), free(container), NULL);
		}
		container = ft_strjoin(container, buffer);
		if (!container)
			return (NULL);
	}
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container = ft_read_line(container, fd);
	if (!container)
		return (NULL);
	line = ft_extract_line(container);
	if (!line)
	{
		free(container);
		container = NULL;
	}
	container = ft_remain_line(container);
	return (line);
}
int main()
{
    int fd = open("test", O_RDONLY);
    char *test;
    //while ((test = get_next_line(0)) != NULL)
    //{
		//test = get_next_line(fd);
      //  printf("%s", test);
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
        //free(test);
    //}
   // printf("\n");
    close(fd);
    return 0; 
}