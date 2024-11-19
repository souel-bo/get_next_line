/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:53:04 by souel-bo          #+#    #+#             */
/*   Updated: 2024/11/19 20:31:29 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*mal;

	if (!s1)
		return (NULL);
	i = 0;
	mal = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!mal)
		return (NULL);
	while (s1[i])
	{
		mal[i] = s1[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_lenght;
	size_t	src_lenght;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	dest_lenght = ft_strlen(dest);
	src_lenght = ft_strlen(src);
	i = 0;
	if (dest_lenght >= size)
		return (src_lenght + size);
	while (src[i] && i < size - dest_lenght - 1)
	{
		dest[dest_lenght + i] = src[i];
		i++;
	}
	dest[i + dest_lenght] = '\0';
	return (dest_lenght + src_lenght);
}
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	lenght;
	size_t	i;

	lenght = ft_strlen(src);
	if (dstsize == 0)
		return (lenght);
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lenght);
}
char *ft_strjoin(char const *s1, char const *s2)
{
    char *aloc_str;
    size_t len;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));

    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    aloc_str = malloc(len);
    if (!aloc_str)
        return (NULL);

    ft_strlcpy(aloc_str, s1, len);
    ft_strlcat(aloc_str, s2, len);
    return (aloc_str);
}