#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    const char *p = s;
    while (*p)
    {
        p++;
    }
    return (p - s);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i = 0;
    size_t len = ft_strlen(src);
    if (dstsize == 0)
    {
        return (len);
    }
    while (src[i] && i < dstsize - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (len);
}

size_t ft_strlcat(char *dest, const char *src, size_t dstsize)
{
    size_t len_src = ft_strlen(src);
    size_t len_dest = ft_strlen(dest);
    if (dstsize <= len_dest)
    {
        return (len_src + dstsize);
    }
    size_t i = 0;
    while (src[i] && i < dstsize - len_dest -1)
    {
        dest[len_dest + i] = src[i];
        i++; 
    }
    dest[len_dest + i] = '\0';
    return (len_src + len_dest);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        return NULL;
    }
    size_t allocation_size = ft_strlen(s1) + ft_strlen(s2) + 1;
    char *all = (char*)malloc(sizeof(char) * (allocation_size));
    if (all == NULL)
    {
        return NULL;
    }
    ft_strlcpy(all, s1, allocation_size);
    ft_strlcat(all, s2, allocation_size);
    return all;
}

char *ft_strchr(const char *s, int c)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
        {
            return (char *)&s[i];
        }
        i++;
    }
    if (c == '\0')
    {
        return (char*)&s[i];
    }
    return NULL;
}