/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:21:02 by souel-bo          #+#    #+#             */
/*   Updated: 2024/11/21 09:22:27 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  23
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen_up(char *s, char c);
char	*ft_strdup_up(char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_up(char *s1, char *s2);
#endif