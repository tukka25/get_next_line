/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:33:54 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/07 15:56:33 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_less_than_buffersize(char *buf, size_t buf_size)
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
	return (buf);
}

char	*sa3ad(char *tmp, char *buf, size_t buf_size)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	str = ft_strjoin(tmp, buf);
	buf = malloc(buf_size * sizeof(char));
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
	buf_size = 4;
	buf = malloc(buf_size + 1);
	tmp = malloc(buf_size + 1);
	// printf("at first = %s", buf);
	j = read(fd, buf, buf_size);
	buf[j] = '\0';
	while (j != 0 && checker(buf) == 1)
	{
		if (j < buf_size)
		{
			buf_size = j;
			buf = rest_less_than_buffersize(buf, buf_size);
		}
		tmp = sa3ad(tmp, buf, buf_size);
		j = read(fd, buf, buf_size);
		buf[j] = '\0';
	}
	if (j < buf_size)
		buf = rest_less_than_buffersize(buf, buf_size);
	tmp = sa3ad(tmp, buf, buf_size);
	if (j <= buf_size && j != 0)
		buf = saving(buf, buf_size);
		
	return (tmp);
}

char	*saving(char *buf, size_t buf_size)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(buf_size);
	i = 0;
	j = 0;
	if (checker(buf) == 0)
	{
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
			{
				while (buf[i] != '\0')
				{
					str[j++] = buf[i + 1];
					i++;
				}
			}
			i++;
		}
		return (str);
	}
	return (buf);
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
	close(fd);
}