/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:29:40 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/27 14:02:13 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>
# include <ctype.h>

typedef struct s_vars
{
	int		i;
	int		d;
	char	*tmp2;
	char	*s;
	char	*f;
}	t_vars;

typedef struct read_vars
{
	char			*tmp;
	char			*str;
	int				n_pos;
	int				j;
}	t_rvars;
char	*get_next_line(int fd);

size_t	ft_strlen_and_ft_strchr(char *str, int c, int n);

char	*ft_strdup(char *s1);

char	*ft_strjoin(char *s1, char *s2);

char	*joining(char *str, char *tmp, int j);

char	*rest_less(char *buf, int j);

char	*ft_substr(char *s, unsigned int start, size_t len);

char	*saving(char *buf, int d);

char	*handle(char *buf, int j);
// void	check_leaks();
#endif