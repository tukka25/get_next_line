/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:29:40 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/11 17:46:27 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_memmove(char *dst, char *src, size_t len);

char	*joining(char *tmp, char *buf, size_t buf_size, int j);

char	*rest_less(char *buf, int j, size_t buf_size);

int		ft_strchr(char *s, int c);

char	*ignoring(char *tmp);

int		checker(char *buf);

char	*saving(char *buf, char *tmp);

char	*ft_strdup(const char *s1);

int		saving_len(char	*buf);
#endif