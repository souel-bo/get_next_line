#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 23

#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
char	*get_next_line(int fd);
size_t	ft_strlen_up(char *s, char c);
char	*ft_strdup_up(char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_up(char *s1, char *s2);
#endif