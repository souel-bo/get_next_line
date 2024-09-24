#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *adress = NULL;
    char *line = NULL;          
    char buffer[BUFFER_SIZE + 1];
    char *new_line;
    int readed;
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return NULL;
    }
    line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!line)
    {
        return NULL;
    }
    line[0] = '\0';
    readed = read(fd, buffer, BUFFER_SIZE);
    while (readed > 0)
    {
        buffer[readed] = '\0';
        new_line = ft_strchr(buffer, '\n');
        if (new_line)
        {
            size_t length_bet = new_line - buffer + 1;
            line = ft_strjoin(line, buffer);
            size_t length_left = readed - length_bet;
            if (length_left > 0)
            {
                adress = (char *)malloc(sizeof(char) * (length_left + 1));
                if (adress)
                {
                    ft_strlcpy(adress, new_line + 1, length_left + 1);
                }
            }
            return line;
        }
        else
        {
            line = ft_strjoin(line, buffer);
        }

        readed = read(fd, buffer, BUFFER_SIZE);
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
    int fd = open("test.txt", O_RDONLY);
    char *test;
    while ((test = get_next_line(fd)) != NULL)
    {
        printf("%s", test);
        free(test);
    }
    printf("\n");
    close(fd);
    return 0; 
}
