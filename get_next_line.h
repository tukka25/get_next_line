/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:29:40 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/13 21:17:22 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>
#include <ctype.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char *s1, char *s2);

char	*joining(char *str, char *tmp, int j);

char	*rest_less(char *buf, int j);

int		ft_strchr(char *s, int c);

char	*ignoring(char *tmp);

char	*ft_substr(char *s, unsigned int start, size_t len);

char	*ft_strjoin_original(char const *s1, char const *s2);

void	check_leaks();

char	*saving(char *buf, int d);

// char	*handle(char *buf, int j);

#endif