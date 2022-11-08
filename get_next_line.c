/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:33:54 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/08 16:34:42 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_less_than_buffersize(char *buf, size_t buf_size, char *tmp)
{
	size_t	i;
	int		j;
	size_t	len;

	j = 0;
	i = buf_size;
	len = ft_strlen(buf) - i;
	while (j < i)
		j++;
	buf[j] = '\0';
	// printf("buf = %s", buf);
	tmp = sa3ad(tmp, buf, buf_size);
	// printf("tmp = %s", tmp);
	return (tmp);
}

char	*sa3ad(char *tmp, char *buf, size_t buf_size)
{
	char	*str;
	int		i;
	char	*tmp2;

	i = 0;
	str = NULL;
	// tmp2 = ft_strdup()
	str = ft_strjoin(tmp, buf);
	buf = malloc((buf_size + 1) * sizeof(char));
	return (str);
}

int	checker(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	size_t			buf_size;
	static char		*buf;
	int				j;
	char			*tmp;

	tmp = NULL;
	buf_size = 3;
	if (buf)
		tmp = saving(buf, tmp);
	else
		tmp = malloc(buf_size + 1);
	buf = malloc(buf_size + 1);
	j = read(fd, buf, buf_size);
	if (j == 0)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	while (ft_strchr(buf, '\n') == 0 && j != 0)
	{
		tmp = sa3ad(tmp, buf, buf_size);
		j = read(fd, buf, buf_size);
		if (!buf)
			return (NULL);
	}
	if (j < buf_size)
	{
		// printf("\nbuf = %s", buf);
		buf_size = j;
		buf = rest_less_than_buffersize(buf, buf_size, tmp);
	// 	// printf("after buf = %s", buf);
	}
	// tmp = sa3ad(tmp, buf, buf_size);
	return (tmp);
}

char	*saving(char *buf, char *tmp)
{
	char	*str;

	str = ft_strdup(buf);
	tmp = ft_strjoin(tmp, str);
	return (tmp);
}

int main()
{
	int fd;
	int i = 0;
	char str[100];
	
	fd = open("f.txt", O_RDONLY);
		char *line;
		line = get_next_line(fd);
		// free(line);
	while(line != NULL)
	{
		printf("%s" , line);
		line = get_next_line(fd);
	}
	
	// printf("%s" , line);
	close(fd);
}