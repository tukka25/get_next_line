/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:29:40 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/15 15:45:23 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// # ifndef BUFFER_SIZE
// # define BUFFER_SIZE 42
// # endif
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_memmove(char *dst, char *src, size_t len);

char	*joining(char *tmp, char *buf, int j);

char	*rest_less(char *buf, int j);

int		ft_strchr(char *s, int c);

char	*ignoring(char *tmp);

char	*saving(char *buf, char *tmp);

void	*ft_calloc(size_t count, size_t size);
#endif