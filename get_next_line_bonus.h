#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#define MAX_FD 1024

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 23

#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
char *get_next_line(int fd);
size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlcat(char *dest, const char *src, size_t dstsize);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *s);
#endif