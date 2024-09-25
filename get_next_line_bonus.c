#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
    static char *address[MAX_FD] = {NULL};
    char *line = NULL;          
    char buffer[BUFFER_SIZE + 1];
    char *new_line;
    int read_bytes;

    if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
        return NULL;

    line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!line)
        return NULL;
    line[0] = '\0';
    if (address[fd])
    {
        new_line = ft_strchr(address[fd], '\n');
        if (new_line)
        {
            *new_line = '\0';
            line = ft_strdup(address[fd]);
            char *temp = ft_strdup(new_line + 1);
            free(address[fd]);
            address[fd] = temp;
            return line;
        }
        else
        {
            line = ft_strdup(address[fd]);
            free(address[fd]);
            address[fd] = NULL;
        }
    }

    read_bytes = read(fd, buffer, BUFFER_SIZE);
    while (read_bytes > 0)
    {
        buffer[read_bytes] = '\0';
        new_line = ft_strchr(buffer, '\n');
        if (new_line)
        {
            *new_line = '\0';
            line = ft_strjoin(line, buffer);
            address[fd] = ft_strdup(new_line + 1);
            return line;
        }
        else
        {
            line = ft_strjoin(line, buffer);
        }

        read_bytes = read(fd, buffer, BUFFER_SIZE);
    }

    if (line[0] == '\0')
    {
        free(line);
        return NULL;
    }
    return line;
}

int main()
{
    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    char *line;

    while (1)
    {
        line = get_next_line(fd1);
        if (line)
        {
            printf("%s", line);
            free(line);
        }
        
        line = get_next_line(fd2);
        if (line)
        {
            printf("%s", line);
            free(line);
        }

        if (!line)
            break;
    }

    close(fd1);
    close(fd2);
    return 0; 
}